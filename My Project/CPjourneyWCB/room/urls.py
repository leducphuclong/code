from django.urls import path
from . import views

urlpatterns = [
    path('', views.rooms, name='rooms'),
    path('chat/', views.chat_page, name='chat_page'),
    path('<slug:slug>/', views.room, name = 'room'),
]