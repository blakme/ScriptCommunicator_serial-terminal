/***************************************************************************
**                                                                        **
**  ScriptCommunicator, is a tool for sending/receiving data with several **
**  interfaces.                                                           **
**  Copyright (C) 2014 Stefan Zieker                                      **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Stefan Zieker                                        **
**  Website/Contact: http://sourceforge.net/projects/scriptcommunicator/  **
****************************************************************************/

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include "PCANBasicClass.h"
#include <QLabel>
#include <QToolButton>
#include <QComboBox>
#include <QSignalMapper>

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
class SettingsDialog;
}

class QIntValidator;

QT_END_NAMESPACE

///Connection type.
typedef enum
{
    CONNECTION_TYPE_SERIAL_PORT = 0,
    CONNECTION_TYPE_TCP_CLIENT,
    CONNECTION_TYPE_TCP_SERVER,
    CONNECTION_TYPE_UDP_SOCKET,
    CONNECTION_TYPE_CHEETAH_SPI_MASTER,
    CONNECTION_TYPE_PCAN

}ConnectionType;

///Decimal type.
typedef enum
{
    DECIMAL_TYPE_UINT8 = 0,
    DECIMAL_TYPE_INT8,
    DECIMAL_TYPE_UINT16,
    DECIMAL_TYPE_INT16,
    DECIMAL_TYPE_UINT32,
    DECIMAL_TYPE_INT32,

}DecimalType;

///Endianess.
typedef enum
{
    LITTLE_ENDIAN_TARGET = 0,
    BIG_ENDIAN_TARGET


}Endianess;

///The settings for the serial port.
typedef struct
{

    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
    bool setRTS;
    bool setDTR;
}SerialPortSettings;

///Settings for a socket.
typedef struct
{
    quint16 partnerPort;
    QString adress;
    quint16 ownPort;
    QString socketType;
    quint8 proxySettings;
    QString proxyAddress;
    quint16 proxyPort;
    QString proxyUserName;
    QString proxyPassword;
}SocketSetings;

///Settings for a cheetah spi interface.
typedef struct
{
    quint16 port;
    quint16 baudRate;
    quint16 mode;
    quint8 chipSelect;
}CheetahSpiSettings;

///Settings for a pcan interface.
typedef struct
{
    quint8 channel;
    quint32 baudRate;
    bool busOffAutoReset;
    bool powerSupply;
    bool filterExtended;
    QString filterFrom;
    QString filterTo;
}PcanSettings;

///Struct which holds all settings from the settings window.
struct Settings
{
    ///The path to external script editor.
    QString scriptEditorPath;

    ///The connection type.
    ConnectionType connectionType;

    ///The socket settings.
    SocketSetings socketSettings;

    ///Settings for the serial port.
    SerialPortSettings serialPort;

    ///Settings for a cheetah spi interface.
    CheetahSpiSettings cheetahSpi;

    ///Settings for the pcan interface.
    PcanSettings pcanInterface;

    ///The target endianess of the target.
    Endianess targetEndianess;

    ///The current tab index of the settings dialog tab widget.
    quint8 settingsDialogTabIndex;

    /**************Console settings**********************/
    ///True if the received data (main interface) shall be shown in the console.
    bool showReceivedDataInConsole;

    ///True if the send data (main interface) shall be shown in the console.
    bool showSendDataInConsole;

    ///True if timestamps shall be created in the consoles.
    bool generateTimeStampsInConsole;

    ///The console timestamp interval
    int timeStampIntervalConsole;

    ///Max. numbers of chars in the consoles.
    quint32 maxCharsInConsole;

    ///True if the can meta information (id and type) shall be shown in the consoles.
    bool showCanMetaInformationInConsole;

    ///True if the received/sended data (main interface) shall be displayed as decimal numbers in console.
    bool showDecimalInConsole;

    ///True if the received/sended data (main interface) shall be displayed as hexadecimal numbers in console.
    bool showHexInConsole;

    ///True if the received/sended data (main interface) shall be displayed as ascii characters in console.
    bool showAsciiInConsole;

    ///True if the mixed console shall be shown.
    bool showMixedConsole;

    ///True if the binary console shall be shown.
    bool showBinaryConsole;

    ///True if the can tab shall be shown.
    bool showCanTab;

    ///If true then the consoles do not scroll to the end after adding new data.
    bool lockScrollingInConsole;

    ///The consoles font.
    QString stringConsoleFont;

    ///The consoles font size.
    QString stringConsoleFontSize;

    ///The min. console font size.
    static const int MIN_FONT_SIZE = 4;

    ///The max. console font size.
    static const int MAX_FONT_SIZE = 20;

    ///The consoles update interval.
    quint32 updateIntervalConsole;

    ///The color of receive data.
    QString consoleReceiveColor;

    ///The color of send data.
    QString consoleSendColor;

    ///The background color of the consoles.
    QString consoleBackgroundColor;

    ///The color of timestamps and messages.
    QString consoleMessageAndTimestampColor;

    ///Colors for mixed console
    QString consoleMixedAsciiColor;
    QString consoleMixedDecimalColor;
    QString consoleMixedHexadecimalColor;
    QString consoleMixedBinaryColor;

    ///New line after ... number of sent/received bytes (0=off).
    quint32 consoleNewLineAfterBytes;

    ///New line after ... ms send/receive pause (0=off).
    quint32 consoleNewLineAfterPause;
    ///New line at.
    quint16 consoleNewLineAt;

    ///Time stamp at.
    quint16 consoleTimestampAt;

    ///Create time stamp at.
    quint16 consoleCreateTimestampAt;

    ///This is sent/used for the enter key (console, message dialog and ascii sequence in the send window).
    QString consoleSendOnEnter;

    ///The console time stamp format.
    QString consoleTimestampFormat;

    ///The console script.
    QString consoleScript;

    ///True if the custom console shall be shown.
    bool consoleShowCustomConsole;

    ///True if the custom console script shall run in the script debugger.
    bool consoleDebugCustomConsole;

    ///The type of the decimals in the decimal console.
    DecimalType consoleDecimalsType;

    /**************Log settings**********************/
    ///True if the received/sended data (main interface) shall logged in a html log.
    bool htmlLogFile;

    ///The name of the html log file.
    QString htmlLogfileName;

    ///True if the received/sended data (main interface) shall logged in a txt log.
    bool textLogFile;

    ///The name of the text log file.
    QString textLogfileName;

   ///True if the received data (main interface) shall be logged.
    bool writeReceivedDataInToLog;

    ///True if the sended data (main interface) shall be logged.
    bool writeSendDataInToLog;

    ///True if the can meta information (id and type) shall be written into the logs.
    bool writeCanMetaInformationInToLog;

    ///True if timestamps shall be created in the log.
    bool generateTimeStampsInLog;

    ///If true then a timestamp is appended at the log filename..
    bool appendTimestampAtLogFileName;

    ///The console timestamp interval
    int timeStampIntervalLog;

    ///Time stamp at.
    quint16 logTimestampAt;

    ///Create time stamp at.
    quint16 logCreateTimestampAt;

    ///The html log font.
    QString stringHtmlLogFont;

    ///The html log font size.
    QString stringHtmlLogFontSize;

    ///True if the received/sended data (main interface) shall be added as decimal numbers in the log.
    bool writeDecimalInToLog;

    ///True if the received/sended data (main interface) shall be added as hexadecimal numbers in the log.
    bool writeHexInToLog;

    ///True if the received/sended data (main interface) shall be added as ascii characters in the log.
    bool writeAsciiInToLog;

    ///True if the received/sended data (main interface) shall be added as binary characters in the log.
    bool writeBinaryInToLog;

    ///New line after ... number of sent/received bytes (0=off).
    quint32 logNewLineAfterBytes;

    ///New line after ... ms send/receive pause (0=off).
    quint32 logNewLineAfterPause;

    ///New line at.
    quint16 logNewLineAt;

    ///The log time stamp format.
    QString logTimestampFormat;

    ///The log script.
    QString logScript;

    ///True if the custom log shall be generated.
    bool logGenerateCustomLog;

    ///True if the custom log script shall run in the script debugger.
    bool logDebugCustomLog;

    ///The name of the custom log file.
    QString customLogfileName;

    ///The type of the decimals in the log.
    DecimalType logDecimalsType;


};

///Class which represents the settings window.
class SettingsDialog : public QDialog
{
    Q_OBJECT

public:

    explicit SettingsDialog(QAction *actionLockScrolling);
    ~SettingsDialog();

    ///Default value for the max. characters in console text edit.
    static const int DEFAULT_VALUE_MAX_CHARS_IN_EDIT_BOX = 100000;

    ///Default value for the time stamp interval.
    static const int DEFAULT_VALUE_TIME_STAMP_INTERVAL = 100;

    ///Default value for the console update interval.
    static const int DEFAULT_CONSOLE_UPDATE_INTERVAL = 200;

    ///Min. value for the console update interval.
    static const int MIN_CONSOLE_UPDATE_INTERVAL = 1;

    ///Max. value for the console update interval.
    static const int MAX_CONSOLE_UPDATE_INTERVAL = 10000;

    ///The max. baudrate.
    static const int MAX_BAUDRATE = 100000000;

    ///Returns the current settings.
    const Settings* settings() const;

    ///Updates the settings struct (m_currentSettings).
    void updateSettings();

    ///Updates a decimal type.
    void updatesDecimalsTypes(DecimalType* type, QComboBox *typeBox);

    ///Sets a decimal combo box.
    void setDecimalComboBox(DecimalType type, QComboBox* typeBox);

    ///Returns the text color from a button.
    QString getColorStringFromButton(QToolButton* button);

    ///Sets the text color of a button.
    void setButtonColorFromString(QString colorString, QToolButton* button);

    ///Sets m_interfaceSettingsCanBeChanged.
    void setInterfaceSettingsCanBeChanged(bool interfaceSettingsCanBeChanged);

    ///Initializes the interface tabs.
    void initializeInterfaceTabs(void);

    ///Returns the current pcan baudrate;
    quint16 getPcanBaudrate();

    ///Is called if a color button button is pressed.
    void colorButtonPressed(QToolButton* button);

    ///Shows (socket tab) all local ip addresses found on this PC.
    void showAllLocalIpAddresses(void);

    ///Converts a pcan baudrate.
    static QString convertPcanBaudrate(quint16 baudrate);

    ///In this event filter function the mouse pressed event for serialPortInfoListBox
    ///is intercepted and a scan for available serial port is done.
    ///The previous elements of serialPortInfoListBox are replaced by the result of the scan.
    ///After this the mouse event is passed to the parent of serialPortInfoListBox.
    bool eventFilter(QObject *obj, QEvent *ev);
public slots:

    ///Sets all settings in the gui and the settings struct (m_currentSettings).
    void setAllSettingsSlot(Settings& settings, bool setTabIndex);
private slots:

    ///Is called if the user presses the search console script button.
    void searchConsoleScriptSlot();

    ///Is called if the user presses the search log script button.
    void searchLogScriptSlot();

    ///Is called if a filter radio button is pressed.
    void setFilterRadioButtonPressedSlot(void);

    ///Detects pcan usb interface.
    void detectPcanSlot(void);

    ///This slot function is called if the user presses the lock scroll action in the main window.
    void lockScrollingSlot(void);

    ///This slot function is called if the selected com port has been changed.
    void comPortChangedSlot(QString text);

    ///The slot function for the close button.
    void closeButtonPressed();

    ///This slot function is called if the selected baudrate has been changed.
    ///If the user selects the custom value, then the combobox becomes editable and a int validator
    ///is added (only the first time)
    void checkCustomBaudRatePolicySlot(int idx);

    ///This slot function is called if the selected console time stamp at has been changed.
    ///If the user selects the custom value, then the combobox becomes editable and a int validator
    ///is added (only the first time).
    void checkCustomConsoleTimestampAtSlot(int idx);

    ///This slot function is called if the selected log time stamp at has been changed.
    ///If the user selects the custom value, then the combobox becomes editable and a int validator
    ///is added (only the first time).
    void checkCustomLogTimestampAtSlot(int idx);

    ///This slot function is called if the selected console new line has been changed.
    ///If the user selects the custom value, then the combobox becomes editable and a int validator
    ///is added (only the first time)
    void checkCustomConsoleNewLineAtSlot(int idx);

    ///This slot function is called if the selected log new line has been changed.
    ///If the user selects the custom value, then the combobox becomes editable and a int validator
    ///is added (only the first time)
    void checkCustomLogNewLineAtSlot(int idx);

    ///Slot function for the delete text log button.
    void deleteTextLogButtonPressedSlot(void);

    ///Slot function for the search text log button.
    void searchTextLogButtonPressedSlot(void);

    ///Slot function for the delete html log button.
    void deleteHtmlLogButtonPressedSlot(void);

    ///Slot function for the search html log button.
    void searchHtmlLogButtonPressedSlot(void);

    ///Slot function for the delete custom log button.
    void deleteCustomLogButtonPressedSlot(void);

    ///Slot function for the search custom log button.
    void searchCustomLogButtonPressedSlot(void);

    ///Slot function for the activate html log check box.
    void htmLogActivatedSlot(bool activated);

    ///Slot function for the activate text log check box.
    void textLogActivatedSlot(bool activated);

     ///Slot function for the activate custom console check box.
    void customConsoleActivatedSlot(bool activated);

    ///Slot function for the activate custom log check box.
    void customLogActivatedSlot(bool activated);

    ///This slot function is called if a text from a gui element has been changed.
    ///It updates the gui elements and the settings struct (m_currentSettings).
    void textFromGuiElementChangedSlot(QString text);


    ///This slot function is called if a selection from a check box has been changed.
    ///It updates the settings struct (m_currentSettings).
    void stateFromCheckboxChangedSlot(int state);

    ///Is called if the user clickes a proxy radio button.
    void proxyRadioButtonClickedSlot(void);

    ///Slot function for the search script editor button.
    void searchScriptEditorButtonPressedSlot(void);

    ///This slot function is called if the value of the script editor path line edit has been changed.
    void scriptEditorPathLineEditTextChangedSlot(QString path);

    ///Slot function for the cheetah scan button.
    void cheetahScanButtonSlot(void);

    ///This slot function is called if the connection type has been changed.
    void conectionTypeChangesSlot(QString text);

    ///Slot function for the edit custom console script button.
    void editCustomConsoleScriptSlot(void);

    ///Slot function for the edit custom log script button.
    void editCustomLogScriptSlot(void);

    ///The state of the 'append time stamp at logs' check box has been changed.
    void appendTimestampAtLogsChangedSlot(int newState);

Q_SIGNALS:

    ///The state of the 'append time stamp at logs' check box has been changed.
    void appendTimestampAtLogsChangedSignal(void);

    ///This signal is emitted if the logs (html and text) have to be deleted.
    void deleteLogFileSignal(QString logType);

    ///This signal is emitted if the global configuration has to be saved.
    void configHasToBeSavedSignal();

    ///This signal is emitted if the connection type has been changed.
    void conectionTypeChangesSignal();

    ///This signal is emitted if the html log has to be activated.
    void htmlLogActivatedSignal(bool);

    ///This signal is emitted if the path to the external script editor has been changed.
    void scriptEditorPathHasBeenChangedSignal(QString);

    ///This signal is emitted if the text log has to be activated.
    void textLogActivatedSignal(bool);

    ///This signal is emitted if the custom log has to be activated.
    void customLogActivatedSignal(bool);

    ///This signal is emitted if the custom console settings have been changed.
    void customConsoleSettingsChangedSignal(void);

    ///This signal is emitted if the custom log settings have been changed.
    void customLogSettingsChangedSignal(void);

private:
    ///Fills the gui elements which correspond to the serial port.
    void fillSerialPortParameters();

    ///Reads the information from all available serial port.
    QVector<QStringList> getSerialPortsInfo();
    QSignalMapper *mapColorButtons;

private:
    ///The user interface.
    Ui::SettingsDialog *m_userInterface;

    ///The current settings.
    Settings m_currentSettings;

    ///Pointer to the lock scrolling action in the main window.
    QAction *m_actionLockScrolling;

    ///True if the interface settings can be changed.
    bool m_interfaceSettingsCanBeChanged;

    ///PCAN Interface.
    PCANBasicClass* m_pcanInterface;

};

#endif // SETTINGSDIALOG_H
