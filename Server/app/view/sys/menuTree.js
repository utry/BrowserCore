Ext.define('UTMP.view.sys.menuTree',{
    extend:'Ext.tree.Panel',
    alias: 'widget.menuTree',
    region: 'west',
    margin: '0 2 2 2',
    store:'UTMP.store.sys.menus',
    width: 230,
    title: '系统菜单',
    collapsible: true,
    rootVisible: false,
    autoScroll: true
});


