Ext.util.Observable.observe(Ext.data.Connection,{
    beforerequest: function(conn, options, eOpts){
        options.url = "http://10.0.7.109:8080/UTMP/"+options.url;
    }
});
Ext.application({
    name:'UTMP',
    appFolder:'http://10.0.7.109:8080/UTMP/app',
    controllers:["sys.index"],
    views:["sys.menuTree","sys.titleBar","sys.contentTabPanel"],
    launch:function(){    
        Ext.create('Ext.Viewport',{
           layout:'border',
           items:[
               {xtype: 'menuTree'},
               {xtype: 'titleBar'},
               {xtype: 'contentTabPanel'}
           ]
        });
    }
});

