from django.shortcuts import render
from django.conf import settings
from django.contrib.auth.decorators import login_required
from .models import Room, ChatMessage
from openai import AzureOpenAI
import os


# Create your views here.

@login_required

def rooms(request):
    rooms = Room.objects.all()
    return render(request, 'room/rooms.html', {'rooms': rooms})

@login_required
def room(request, slug):
    room = Room.objects.get(slug=slug)
    return render(request, 'room/room.html', {'room': room})

@login_required
def chat_page(request):
    context = {}

    client = AzureOpenAI(
        azure_endpoint=os.getenv("AZURE_OPENAI_ENDPOINT"),
        api_key=os.getenv("AZURE_OPENAI_KEY"),
        api_version="2023-05-15"
    )

    if request.method == 'POST':
        user_input = request.POST.get('message')
        if user_input:
            # Store user's message in the database
            ChatMessage.objects.create(user=request.user, content=user_input)

            # Retrieve all messages from the database
            messages = ChatMessage.objects.all()

            # Use the OpenAI API to get a response
            response = client.chat.completions.create(
                model="GPT35TURBO",
                messages=[
                    {"role": "system", "content": "You are a helpful assistant."},
                ] + [{"role": "user", "content": message.content} for message in messages]
            )

            # Store AI's response in the database
            ai_response = response.choices[0].message.content
            ChatMessage.objects.create(user=None, content=ai_response)

            context['bot_response'] = ai_response

    # Retrieve all messages from the database for display
    context['messages'] = ChatMessage.objects.all()

    return render(request, 'room/chat_page.html', context)