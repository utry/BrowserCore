Ext.define("UTMP.store.sys.menus",{
    extend:"Ext.data.TreeStore",
    model:'UTMP.model.sys.menu',
    autoLoad:true,
    //data:[{"MenuLevel":1,"IsCheck":0,"SubMenus":[{"MenuLevel":2,"IsCheck":0,"SubMenus":[]}]}],
    root: {
        text: '.',
        id: 'root',
        expanded: true,
        children: []
    },
    defaultRootProperty: 'SubMenus',
    proxy: {
        type: 'ajax',
        reader: 'json',
        url: 'testData/menuData.json'
    }
});