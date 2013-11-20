Ext.define("UTMP.view.sys.titleBar", {
    extend:'Ext.toolbar.Toolbar',
    alias: 'widget.titleBar',
    region: 'north',
    border:0,
    items: [
        {
            xtype: 'tbtext',
            margin: '0 10 0 10',
            style: '{font-weight:bold;color:#04408c;}',
            text: 'UTMP远传技术管理平台'
        },
        '->',
        {
            xtype:'splitbutton',
            text: '设置',
            handler: function () {
                alert("The button was clicked");
            },
            menu: new Ext.menu.Menu({
                items: [
                    { text: '打开调试器', handler: function () { QtWinFrame.SetFrameWindow(2); } },
                    { text: '刷新', handler: function () { QtWinFrame.SetFrameWindow(4); } }
                ]
            })
        },
        {
            text: '最小化',
            handler: function () {
                QtWinFrame.SetFrameWindow(1);
            }
        },
        {
            text:'关闭',
            handler: function () {
                QtWinFrame.SetFrameWindow(0);
            }
        }
    ]
});


