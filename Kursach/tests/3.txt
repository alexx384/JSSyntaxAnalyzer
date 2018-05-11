function TinyMCE_Engine()
{
    this.majorVersion = "2";
    this.minorVersion = "0.5";
    this.releaseDate = "2006-03-21";
    this.instances = new Array();
    this.switchClassCache = new Array();
    this.windowArgs = new Array();
    this.loadedFiles = new Array();
    this.configs = new Array();
    this.currentConfig = 0;
    this.eventHandlers = new Array();
    var ua = navigator.userAgent;
    this.isMSIE = (navigator.appName == "Microsoft Internet Explorer");
    this.isMSIE5 = this.isMSIE && (ua.indexOf('MSIE 5') != -1);
    this.isMSIE5_0 = this.isMSIE && (ua.indexOf('MSIE 5.0') != -1);
    this.isGecko = ua.indexOf('Gecko') != -1;
    this.isSafari = ua.indexOf('Safari') != -1;
    this.isOpera = ua.indexOf('Opera') != -1;
    this.isMac = ua.indexOf('Mac') != -1;
    this.isNS7 = ua.indexOf('Netscape/7') != -1;
    this.isNS71 = ua.indexOf('Netscape/7.1') != -1;
    this.dialogCounter = 0;
    if(this.isOpera)
    {
        this.isMSIE = 1;
        this.isGecko = 0;
        this.isSafari = 0;
    }

    this.idCounter = 0;
};