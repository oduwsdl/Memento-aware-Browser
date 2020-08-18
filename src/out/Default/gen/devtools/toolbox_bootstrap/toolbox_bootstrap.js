function toolboxLoaded(){if(!window.opener){return;}
const app=window.opener['Emulation']['AdvancedApp']['_instance']();app['toolboxLoaded'](document);}
runOnWindowLoad(toolboxLoaded);