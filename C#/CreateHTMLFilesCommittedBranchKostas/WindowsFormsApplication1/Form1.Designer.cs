namespace WindowsFormsApplication1
{
    partial class Form1
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnCreateFilesList = new System.Windows.Forms.Button();
            this.btnCreateFilesAutoList = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnCreateFilesList
            // 
            this.btnCreateFilesList.Location = new System.Drawing.Point(12, 30);
            this.btnCreateFilesList.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnCreateFilesList.Name = "btnCreateFilesList";
            this.btnCreateFilesList.Size = new System.Drawing.Size(159, 50);
            this.btnCreateFilesList.TabIndex = 0;
            this.btnCreateFilesList.Text = "Create Html File";
            this.btnCreateFilesList.UseVisualStyleBackColor = true;
            this.btnCreateFilesList.Click += new System.EventHandler(this.btnCreateFilesList_Click);
            // 
            // btnCreateFilesAutoList
            // 
            this.btnCreateFilesAutoList.Location = new System.Drawing.Point(246, 30);
            this.btnCreateFilesAutoList.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnCreateFilesAutoList.Name = "btnCreateFilesAutoList";
            this.btnCreateFilesAutoList.Size = new System.Drawing.Size(159, 50);
            this.btnCreateFilesAutoList.TabIndex = 1;
            this.btnCreateFilesAutoList.Text = "Create Html File (auto)";
            this.btnCreateFilesAutoList.UseVisualStyleBackColor = true;
            this.btnCreateFilesAutoList.Click += new System.EventHandler(this.btnCreateFilesAutoList_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 17F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(429, 110);
            this.Controls.Add(this.btnCreateFilesAutoList);
            this.Controls.Add(this.btnCreateFilesList);
            this.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "Form1";
            this.Text = "Process";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnCreateFilesList;
        private System.Windows.Forms.Button btnCreateFilesAutoList;
    }
}

