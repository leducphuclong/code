using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace test
{
    public partial class Form1 : Form
    {
        public class Line
        {
            public Point StartPoint { get; set; }
            public Point EndPoint { get; set; }

            public Line(Point startPoint, Point endPoint)
            {
                StartPoint = startPoint;
                EndPoint = endPoint;
            }
        }

        private Point ps;
        private List<Line> lines = new List<Line>();
        public Form1()
        {
            InitializeComponent();
            this.DoubleBuffered = true;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                ps = e.Location;
            }
        }

        
        private void draw_a_line(Point ps, Point pc)
        {
            Graphics g = this.CreateGraphics();
            Pen p = new Pen(Color.Red, 3);
            g.DrawLine(p, ps, pc);
        }
        private void DrawAll()
        {
            foreach (var line in lines)
            {
                draw_a_line(line.StartPoint, line.EndPoint);

            }
        }
        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            lines.Add(new Line(ps, e.Location));
            Refresh();
            DrawAll();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {

                Refresh(); // Forces the form to redraw itself
                DrawAll();
                draw_a_line(ps, e.Location);
            }
        }
    }
}
