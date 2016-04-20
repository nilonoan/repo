Class Config
	Private m_Content
	Private m_FileName
	Private m_FileSystemObject
	Private m_FileObject
	
	Private Sub Class_Initialize
		m_Content = ""
		m_FileName = ""
		Set m_FileSystemObject = Nothing
		Set m_FileObject = Nothing
	End Sub
	
	Public Property Get Content
		m_Content = m_Content
	End Property

	Public Property Let Content(value)
		m_Content = value
	End Property
	
	Public Property Get FileName
		m_FileName = m_FileName
	End Property
	
	Public Property Let FileName(value)
		m_FileName = value
	End Property
	
	Public Function getContent()
		getContent = m_Content
	End Function
	
	Public Sub Open()
		Const ForReading = 1
		Set m_FileSystemObject = CreateObject("Scripting.FileSystemObject")		
		Set m_FileObject = m_FileSystemObject.OpenTextFile(m_FileName, ForReading)
		m_Content = m_FileObject.ReadAll()
	End Sub
	
	Public Sub Close()
		m_FileObject.Close
		Set m_FileObject = Nothing
		Set m_FileSystemObject = Nothing
	End Sub
	
	Public Function GetParam(name)
		Dim lines, x, param
		Dim value
		
		lines = Split(m_Content, vbCrLf)
		
		If UBound(lines) = 0 Then
			lines = Split(m_Content,  Chr(10))
		End If
		
		For x = 0 To UBound(lines)
			param = Split(lines(x), "=")
			If param(0) = "[" + name + "]" Then
				value = param(1)
				Exit For
			End If			
		Next
		
		GetParam = value
	End Function
End Class

Class Mail
	Private m_Outlook
	Private m_MailItem
	Private m_Subject
	Private m_Body
	Private m_MailTo
	
	Private Sub Class_Initialize
		Set m_Outlook = Nothing
		Set m_MailItem = Nothing				
		m_Subject = ""
		m_Body = "" 
		m_MailTo = ""
	End Sub
	
	Public Property Get Subject
		m_Subject = m_Subject
	End Property
	
	Public Property Let Subject(value)
		m_Subject = value
	End Property
	
	Public Property Get Body
		m_Body = m_Body
	End Property
	
	Public Property Let Body(value)
		m_Body = value
	End Property
	
	Public Property Get MailTo
		m_MailTo = m_MailTo
	End Property
	
	Public Property Let MailTo(value)
		m_MailTo = value
	End Property
	
	Public Sub Send()
		Set m_Outlook = CreateObject("Outlook.Application")    
		Set m_MailItem = m_Outlook.CreateItem(0)
		
		With m_MailItem    
			.To = m_MailTo
			.Subject = m_Subject    
			.Body = m_Body    
			.Send    
		End With
		
		Set m_MailItem = Nothing
		Set m_Outlook = Nothing
	End Sub
End Class

Dim ob_cfg, ob_mail
Dim p_subject, p_mailto, p_body, p_datafile
Dim p_content

Set ob_cfg = New Config
ob_cfg.FileName = Mid(WScript.ScriptFullName, 1, Len(WScript.ScriptFullName) - Len(Mid(WScript.ScriptFullName, InStrRev(WScript.ScriptFullName, "\")))) + "\" _
				+ "GitHubNotify.config"
ob_cfg.Open()

p_subject = ob_cfg.GetParam("Email Subject")
p_mailto = ob_cfg.GetParam("Send To")
p_body = ob_cfg.GetParam("Email Body")
p_datafile = ob_cfg.GetParam("Data FileName")

ob_cfg.Close()

ob_cfg.FileName = p_datafile 
ob_cfg.Open()

p_content = ob_cfg.getContent()
ob_cfg.Close()

Set ob_cfg = Nothing
Set ob_mail = New Mail

ob_mail.Subject = p_subject
ob_mail.Body = p_body + VbCrLf + VbCrLf + p_content
ob_mail.MailTo = p_mailto
ob_mail.Send()

Set ob_mail = Nothing

Rem WScript.Echo "Done."