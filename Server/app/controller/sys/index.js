Ext.define("UTMP.controller.sys.index",{
    extend:"Ext.app.Controller",
    views:["sys.menuTree","sys.titleBar","sys.contentTabPanel"],
    models:["UTMP.model.sys.menu"],
    stores:["UTMP.store.sys.menus"],
    init:function(){
 
    }
});


