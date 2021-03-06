/*This script demonstrates sending of user input*/

//Is called if this script shall be exited.
function stopScript() 
{
    scriptThread.appendTextToConsole("script has been stopped");
}

//The dialog is closed.
function UI_DialogFinished(e)
{
	scriptThread.stopScript()
}

function sendSequence()
{
	var data = "send data: ";
	data += UI_LineEdit.text() + " ";
	data += UI_ComboBox.currentText() + " ";
	data += UI_SpinBox.value().toString() +"\n";
	
	if(!scriptThread.sendString(data))
	{
		scriptThread.messageBox("Critical", "Error", "Sending failed. Check if ScriptCommunicator is connected.");
	}
}

scriptThread.appendTextToConsole('script has started');
UI_Dialog.finishedSignal.connect(UI_DialogFinished);

UI_SendButton.clickedSignal.connect(sendSequence)



