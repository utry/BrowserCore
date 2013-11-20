Ext.define("UTMP.model.sys.menu",{
    extend:"Ext.data.Model",
    fields:[
        { name: 'id', type: 'string', mapping: 'MenuID' },
        { name: 'text', type: 'string', mapping: 'MenuName' },
        { name: 'children', type: 'array', mapping: 'SubMenus' },
        { name: 'PagePath', type: 'string' },
        { name: 'IcoPath', type: 'string' },
        { name: 'Target', type: 'string' },
        { name: 'SortNum', type: 'number' },
        { name: 'expanded', type: 'bloolean', defaultValue: false },
        { name: 'leaf', type: 'boolean',convert:function(v,record){
                //console.log(record.data.children.length);
                //return record.data.children.length == 0;
                return false;
        }}
    ]
});


