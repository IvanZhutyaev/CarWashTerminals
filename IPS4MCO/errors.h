#ifndef ERRORS_H
#define ERRORS_H

/*  MC - modbus controller
*   CM - config manager
*
*
*
*
*/

// Also change in Error.qml
#define ERRORS_SUBSYSTEM_MBS 0
#define ERRORS_SUBSYSTEM_UI 100
#define ERRORS_SUBSYSTEM_PLC 1000
#define ERRORS_SUBSYSTEM_PNT 100000

enum Errors {
    No = ERRORS_SUBSYSTEM_MBS,

    // Subsystem: MBS
    // MB
    MCConnect,
    MCDisconnect,
    MCCreateDevice,
    MCTimeout,
    MCConnectionLost,
    MCAlreadyConnected,
    MCQRCode,

    // CM. config check
    CMBaudRate,
    CMConfigParity,
    CMConfigDataBits,
    CMConfigServerAddress,
    CMConfigStopBits,
    CMConfigTimeout,



    // UI-CM
    CMFileOpen = ERRORS_SUBSYSTEM_UI,
    CMFileExist,
    CMFileNotExist,
    CMSyntaxUI,
    CMSyntaxMBS,


    // Subsystem: UI
    UINumberOfPrograms,
    UICodeTiming,
    UIQrCodeDataTimeout,

    UIProgramName1,
    UIProgramName2,
    UIProgramName3,
    UIProgramName4,
    UIProgramName5,
    UIProgramName6,
    UIProgramName7,
    UIProgramName8,

    UIProgramImage1,
    UIProgramImage2,
    UIProgramImage3,
    UIProgramImage4,
    UIProgramImage5,
    UIProgramImage6,
    UIProgramImage7,
    UIProgramImage8,

    UILogo,
    UIMediaBitmap,
    UIMediaVideo,
    UITitle,
    UIPhone,
    UITerminalID,
    UIPauseCost,
    UIEnableMediaVideo,
    UIEnableMediaBitmap,
    UIEnableBitmapVideo,
    UISlideChangeTimeout,
    UIInitSlideChangeMult,
    UIButtonTimeout,
    UIBankTerminalBackTimeout,
    UIBankTerminalErrorTimeout,
    UIBankTerminalSuccessTimeout,



    // Subsystem: PLC
    MCPLC = ERRORS_SUBSYSTEM_PLC,


    // PNT
    PNT = ERRORS_SUBSYSTEM_PNT,
    TimeoutFromPLC,
};


#endif // ERRORS_H
