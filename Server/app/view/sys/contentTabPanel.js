Ext.define("UTMP.view.sys.contentTabPanel", {
    extend:"Ext.tab.Panel",
    alias: 'widget.contentTabPanel',
    region: 'center',
    margin: '0 2 2 2',
    activeTab: 0,
    defaults: {
        autoScroll: true,
        bodyPadding: 4,
        closable: true 
    },
    items: [{
        title: '测试页面',
        html:'<a href="http://www.baidu.com">页内链接</a><br />\
                <a href="http://www.baidu.com" target="_blank">新窗口链接</a><br />\
                <a href="javascript:window.open(\'http://www.baidu.com\')">window.open</a><br />\
                <a href="javascript:window.location.href = \'http://www.baidu.com\'">location.href</a><br />\
                <a href="javascript:window.print();">打印</a><br />\
                <a href="http://dldir1.qq.com/invc/tt/QQBrowserSetup.exe">下载</a><br />\
              <a href="javascript:QtWinFrame.SetFrameWindow(3)">js与QT的互调</a><br />'
    }]
});

