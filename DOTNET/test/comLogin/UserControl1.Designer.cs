namespace comLogin
{
    partial class UserControl1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Longdeptrai = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Longdeptrai
            // 
            this.Longdeptrai.AutoSize = true;
            this.Longdeptrai.Location = new System.Drawing.Point(352, 171);
            this.Longdeptrai.Name = "Longdeptrai";
            this.Longdeptrai.Size = new System.Drawing.Size(250, 25);
            this.Longdeptrai.TabIndex = 0;
            this.Longdeptrai.Text = "Long Đẹp Trai, Đang Kẹp 2";
            this.Longdeptrai.Click += new System.EventHandler(this.label1_Click);
            // 
            // UserControl1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(11F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.Longdeptrai);
            this.Name = "UserControl1";
            this.Size = new System.Drawing.Size(800, 450);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Longdeptrai;
    }
}
