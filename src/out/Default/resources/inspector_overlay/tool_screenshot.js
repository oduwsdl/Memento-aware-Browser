(function(){'use strict';window.viewportSize={width:800,height:600};window.deviceScaleFactor=1;window.emulationScaleFactor=1;window.pageScaleFactor=1;window.pageZoomFactor=1;window.scrollX=0;window.scrollY=0;function reset(resetData){window.viewportSize=resetData.viewportSize;window.deviceScaleFactor=resetData.deviceScaleFactor;window.pageScaleFactor=resetData.pageScaleFactor;window.pageZoomFactor=resetData.pageZoomFactor;window.emulationScaleFactor=resetData.emulationScaleFactor;window.scrollX=Math.round(resetData.scrollX);window.scrollY=Math.round(resetData.scrollY);window.canvas=document.getElementById('canvas');if(window.canvas){window.canvas.width=deviceScaleFactor*viewportSize.width;window.canvas.height=deviceScaleFactor*viewportSize.height;window.canvas.style.width=viewportSize.width+'px';window.canvas.style.height=viewportSize.height+'px';window.context=canvas.getContext('2d');window.context.scale(deviceScaleFactor,deviceScaleFactor);window.canvasWidth=viewportSize.width;window.canvasHeight=viewportSize.height;}}
function setPlatform(platform){window.platform=platform;document.body.classList.add('platform-'+platform);}
function dispatch(message){const functionName=message.shift();window[functionName].apply(null,message);}
Element.prototype.createChild=function(tagName,className){const element=createElement(tagName,className);element.addEventListener('click',function(e){e.stopPropagation();},false);this.appendChild(element);return element;};Element.prototype.createTextChild=function(text){const element=document.createTextNode(text);this.appendChild(element);return element;};Element.prototype.removeChildren=function(){if(this.firstChild){this.textContent='';}};function createElement(tagName,className){const element=document.createElement(tagName);if(className){element.className=className;}
return element;}
String.prototype.trimEnd=function(maxLength){if(this.length<=maxLength){return String(this);}
return this.substr(0,maxLength-1)+'\u2026';};Number.constrain=function(num,min,max){if(num<min){num=min;}else if(num>max){num=max;}
return num;};let anchor=null;let position=null;function currentRect(){return{x:Math.min(anchor.x,position.x),y:Math.min(anchor.y,position.y),width:Math.abs(anchor.x-position.x),height:Math.abs(anchor.y-position.y)};}
function updateZone(){const zone=document.getElementById('zone');if(!position||!anchor){zone.style.display='none';return;}
zone.style.display='block';const rect=currentRect();zone.style.left=rect.x+'px';zone.style.top=rect.y+'px';zone.style.width=rect.width+'px';zone.style.height=rect.height+'px';}
function cancel(){anchor=null;position=null;}
function loaded(){document.documentElement.addEventListener('mousedown',event=>{anchor={x:event.pageX,y:event.pageY};position=anchor;updateZone();event.stopPropagation();event.preventDefault();},true);document.documentElement.addEventListener('mouseup',event=>{if(anchor&&position){const rect=currentRect();if(rect.width>=5&&rect.height>=5){InspectorOverlayHost.send(JSON.stringify(rect));}}
cancel();updateZone();event.stopPropagation();event.preventDefault();},true);document.documentElement.addEventListener('mousemove',event=>{if(anchor&&event.buttons===1){position={x:event.pageX,y:event.pageY};}else{anchor=null;}
updateZone();event.stopPropagation();event.preventDefault();},true);document.documentElement.addEventListener('keydown',event=>{if(anchor&&event.key==='Escape'){cancel();updateZone();event.stopPropagation();event.preventDefault();}},true);}
const style=`
body {
  cursor: crosshair;
}
#zone {
  background-color: #0003;
  border: 1px solid #fffd;
  display: none;
  position: absolute;
}
 `;window.setPlatform=function(platform){const styleTag=document.createElement('style');styleTag.innerHTML=style;document.head.append(styleTag);document.body.onload=loaded;const zone=document.createElement('div');zone.id='zone';document.body.append(zone);setPlatform(platform);};window.reset=function(data){reset(data);};window.dispatch=dispatch;}());