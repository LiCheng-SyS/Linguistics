namespace Spider_Word
{
    partial class FrmMain
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.textUrL = new System.Windows.Forms.TextBox();
            this.labaddress = new System.Windows.Forms.Label();
            this.TextMsg = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // textUrL
            // 
            this.textUrL.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.textUrL.Location = new System.Drawing.Point(168, 18);
            this.textUrL.Multiline = true;
            this.textUrL.Name = "textUrL";
            this.textUrL.Size = new System.Drawing.Size(736, 33);
            this.textUrL.TabIndex = 0;
            this.textUrL.KeyDown += new System.Windows.Forms.KeyEventHandler(this.textUrL_KeyDown);
            // 
            // labaddress
            // 
            this.labaddress.AutoSize = true;
            this.labaddress.Font = new System.Drawing.Font("Microsoft YaHei UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.labaddress.Location = new System.Drawing.Point(40, 30);
            this.labaddress.Name = "labaddress";
            this.labaddress.Size = new System.Drawing.Size(122, 21);
            this.labaddress.TabIndex = 1;
            this.labaddress.Text = "输入网页地址：";
            // 
            // TextMsg
            // 
            this.TextMsg.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.TextMsg.Location = new System.Drawing.Point(0, 122);
            this.TextMsg.Multiline = true;
            this.TextMsg.Name = "TextMsg";
            this.TextMsg.Size = new System.Drawing.Size(945, 410);
            this.TextMsg.TabIndex = 2;
            // 
            // FrmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 17F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(946, 533);
            this.Controls.Add(this.TextMsg);
            this.Controls.Add(this.labaddress);
            this.Controls.Add(this.textUrL);
            this.Name = "FrmMain";
            this.Text = "FrmMain";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textUrL;
        private System.Windows.Forms.Label labaddress;
        private System.Windows.Forms.TextBox TextMsg;
    }
}
