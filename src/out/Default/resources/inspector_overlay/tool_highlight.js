(function(){'use strict';window.viewportSize={width:800,height:600};window.deviceScaleFactor=1;window.emulationScaleFactor=1;window.pageScaleFactor=1;window.pageZoomFactor=1;window.scrollX=0;window.scrollY=0;function reset(resetData){window.viewportSize=resetData.viewportSize;window.deviceScaleFactor=resetData.deviceScaleFactor;window.pageScaleFactor=resetData.pageScaleFactor;window.pageZoomFactor=resetData.pageZoomFactor;window.emulationScaleFactor=resetData.emulationScaleFactor;window.scrollX=Math.round(resetData.scrollX);window.scrollY=Math.round(resetData.scrollY);window.canvas=document.getElementById('canvas');if(window.canvas){window.canvas.width=deviceScaleFactor*viewportSize.width;window.canvas.height=deviceScaleFactor*viewportSize.height;window.canvas.style.width=viewportSize.width+'px';window.canvas.style.height=viewportSize.height+'px';window.context=canvas.getContext('2d');window.context.scale(deviceScaleFactor,deviceScaleFactor);window.canvasWidth=viewportSize.width;window.canvasHeight=viewportSize.height;}}
function setPlatform(platform){window.platform=platform;document.body.classList.add('platform-'+platform);}
function dispatch(message){const functionName=message.shift();window[functionName].apply(null,message);}
Element.prototype.createChild=function(tagName,className){const element=createElement(tagName,className);element.addEventListener('click',function(e){e.stopPropagation();},false);this.appendChild(element);return element;};Element.prototype.createTextChild=function(text){const element=document.createTextNode(text);this.appendChild(element);return element;};Element.prototype.removeChildren=function(){if(this.firstChild){this.textContent='';}};function createElement(tagName,className){const element=document.createElement(tagName);if(className){element.className=className;}
return element;}
String.prototype.trimEnd=function(maxLength){if(this.length<=maxLength){return String(this);}
return this.substr(0,maxLength-1)+'\u2026';};Number.constrain=function(num,min,max){if(num<min){num=min;}else if(num>max){num=max;}
return num;};function blendColors(fgRGBA,bgRGBA){const alpha=fgRGBA[3];return[((1-alpha)*bgRGBA[0])+(alpha*fgRGBA[0]),((1-alpha)*bgRGBA[1])+(alpha*fgRGBA[1]),((1-alpha)*bgRGBA[2])+(alpha*fgRGBA[2]),alpha+(bgRGBA[3]*(1-alpha)),];}
function rgbaToHsla([r,g,b,a]){const max=Math.max(r,g,b);const min=Math.min(r,g,b);const diff=max-min;const sum=max+min;let h;if(min===max){h=0;}else if(r===max){h=((1/6*(g-b)/diff)+1)%1;}else if(g===max){h=(1/6*(b-r)/diff)+1/3;}else{h=(1/6*(r-g)/diff)+2/3;}
const l=0.5*sum;let s;if(l===0){s=0;}else if(l===1){s=0;}else if(l<=0.5){s=diff/sum;}else{s=diff/(2-sum);}
return[h,s,l,a];}
function luminance([rSRGB,gSRGB,bSRGB]){const r=rSRGB<=0.03928?rSRGB/12.92:Math.pow(((rSRGB+0.055)/1.055),2.4);const g=gSRGB<=0.03928?gSRGB/12.92:Math.pow(((gSRGB+0.055)/1.055),2.4);const b=bSRGB<=0.03928?bSRGB/12.92:Math.pow(((bSRGB+0.055)/1.055),2.4);return 0.2126*r+0.7152*g+0.0722*b;}
function contrastRatio(fgRGBA,bgRGBA){const blendedFg=blendColors(fgRGBA,bgRGBA);const fgLuminance=luminance(blendedFg);const bgLuminance=luminance(bgRGBA);const contrastRatio=(Math.max(fgLuminance,bgLuminance)+0.05)/(Math.min(fgLuminance,bgLuminance)+0.05);return contrastRatio;}
const GridArrowTypes={leftTop:'left-top',leftMid:'left-mid',leftBottom:'left-bottom',topLeft:'top-left',topMid:'top-mid',topRight:'top-right',rightTop:'right-top',rightMid:'right-mid',rightBottom:'right-bottom',bottomLeft:'bottom-left',bottomMid:'bottom-mid',bottomRight:'bottom-right',};const gridArrowWidth=3;const gridPageMargin=20;function drawGridNumbers(config,bounds){const showPositiveColumns=config.gridHighlightConfig.showPositiveLineNumbers&&config.positiveColumnLineNumberOffsets;const showPositiveRows=config.gridHighlightConfig.showPositiveLineNumbers&&config.positiveRowLineNumberOffsets;const showNegativeColumns=config.gridHighlightConfig.showNegativeLineNumbers&&config.negativeColumnLineNumberOffsets;const showNegativeRows=config.gridHighlightConfig.showNegativeLineNumbers&&config.negativeRowLineNumberOffsets;if(!showPositiveColumns&&!showPositiveRows&&!showNegativeColumns&&!showNegativeRows){return;}
const labelContainer=document.getElementById('grid-label-container');labelContainer.removeChildren();if(showPositiveColumns){for(const[i,offset]of config.positiveColumnLineNumberOffsets.entries()){const isFirstColumn=offset===0;const isLastColumn=i===config.positiveColumnLineNumberOffsets.length-1;_placeColumnLabel(labelContainer,(i+1).toString(),bounds.minX+offset,bounds.minY,isFirstColumn,isLastColumn);}}
if(showPositiveRows){for(const[i,offset]of config.positiveRowLineNumberOffsets.entries()){const isTopRow=offset===0;const isBottomRow=i===config.positiveRowLineNumberOffsets.length-1;const avoidColumnLabel=(isTopRow&&showPositiveColumns)||(isBottomRow&&showNegativeColumns);_placeRowLabel(labelContainer,(i+1).toString(),bounds.minX,bounds.minY+offset,isTopRow,isBottomRow,avoidColumnLabel);}}
if(showNegativeColumns){for(const[i,offset]of config.negativeColumnLineNumberOffsets.entries()){const index=config.negativeColumnLineNumberOffsets.length*-1+i;const isFirstColumn=offset===0;const positiveOffsets=config.positiveColumnLineNumberOffsets;const isLastColumn=positiveOffsets&&offset===positiveOffsets[positiveOffsets.length-1];_placeColumnLabel(labelContainer,index.toString(),bounds.minX+offset,bounds.maxY,isFirstColumn,isLastColumn,true);}}
if(showNegativeRows){for(const[i,offset]of config.negativeRowLineNumberOffsets.entries()){const index=config.negativeRowLineNumberOffsets.length*-1+i;const isTopRow=offset===0;const positiveOffsets=config.positiveRowLineNumberOffset;const isBottomRow=positiveOffsets&&offset===positiveOffsets[positiveOffsets.length-1];const avoidColumnLabel=(isTopRow&&showPositiveColumns)||(isBottomRow&&showNegativeColumns);_placeRowLabel(labelContainer,index.toString(),bounds.maxX,bounds.minY+offset,isTopRow,isBottomRow,avoidColumnLabel,true);}}}
function _placeRowLabel(labelLayer,label,x,y,isTopRow,isBottomRow,avoidColumnLabel,isNegative){const labelContainer=labelLayer.createChild('div');const labelContent=labelContainer.createChild('div','grid-label-content');labelContent.textContent=label;let verticalAlign='Mid';if(isTopRow&&(y<gridPageMargin||avoidColumnLabel)){verticalAlign='Top';}
if(isBottomRow&&(canvasHeight-y<gridPageMargin||avoidColumnLabel)){verticalAlign='Bottom';}
let horizontalAlign=isNegative?'left':'right';if(!isNegative&&x<gridPageMargin){horizontalAlign='left';}
if(isNegative&&(canvasWidth-x)<gridPageMargin){horizontalAlign='right';}
const arrowType=GridArrowTypes[horizontalAlign+verticalAlign];const labelWidth=_getAdjustedLabelWidth(labelContent);const labelHeight=labelContent.getBoundingClientRect().height;const labelParams=_getLabelPositionByArrowType(arrowType,x,y,labelWidth,labelHeight);labelContent.classList.add(arrowType);labelContent.style.left=labelParams.contentLeft+'px';labelContent.style.top=labelParams.contentTop+'px';}
function _placeColumnLabel(labelLayer,label,x,y,isFirstColumn,isLastColumn,isNegative){const labelContainer=labelLayer.createChild('div');const labelContent=labelContainer.createChild('div','grid-label-content');labelContent.textContent=label;let horizontalAlign='Mid';if(isFirstColumn&&x<gridPageMargin){horizontalAlign='Left';}
if(isLastColumn&&(canvasWidth-x)<gridPageMargin){horizontalAlign='Right';}
let verticalAlign=isNegative?'top':'bottom';if(!isNegative&&y<gridPageMargin){verticalAlign='top';}
if(isNegative&&(canvasHeight-y)<gridPageMargin){verticalAlign='bottom';}
const arrowType=GridArrowTypes[verticalAlign+horizontalAlign];const labelWidth=_getAdjustedLabelWidth(labelContent);const labelHeight=labelContent.getBoundingClientRect().height;const labelParams=_getLabelPositionByArrowType(arrowType,x,y,labelWidth,labelHeight);labelContent.classList.add(arrowType);labelContent.style.left=labelParams.contentLeft+'px';labelContent.style.top=labelParams.contentTop+'px';}
function _getAdjustedLabelWidth(labelContent){let labelWidth=labelContent.getBoundingClientRect().width;if(labelWidth%2===1){labelWidth+=1;labelContent.style.width=labelWidth+'px';}
return labelWidth;}
function _getLabelPositionByArrowType(arrowType,x,y,labelWidth,labelHeight){let contentTop;let contentLeft;switch(arrowType){case GridArrowTypes.leftTop:contentTop=y;contentLeft=x+gridArrowWidth;break;case GridArrowTypes.leftMid:contentTop=y-(labelHeight/2);contentLeft=x+gridArrowWidth;break;case GridArrowTypes.leftBottom:contentTop=y-labelHeight;contentLeft=x+gridArrowWidth;break;case GridArrowTypes.rightTop:contentTop=y;contentLeft=x-gridArrowWidth-labelWidth;break;case GridArrowTypes.rightMid:contentTop=y-(labelHeight/2);contentLeft=x-gridArrowWidth-labelWidth;break;case GridArrowTypes.rightBottom:contentTop=y-labelHeight;contentLeft=x-labelWidth-gridArrowWidth;break;case GridArrowTypes.topLeft:contentTop=y+gridArrowWidth;contentLeft=x;break;case GridArrowTypes.topMid:contentTop=y+gridArrowWidth;contentLeft=x-(labelWidth/2);break;case GridArrowTypes.topRight:contentTop=y+gridArrowWidth;contentLeft=x-labelWidth;break;case GridArrowTypes.bottomLeft:contentTop=y-gridArrowWidth-labelHeight;contentLeft=x;break;case GridArrowTypes.bottomMid:contentTop=y-gridArrowWidth-labelHeight;contentLeft=x-(labelWidth/2);break;case GridArrowTypes.bottomRight:contentTop=y-gridArrowWidth-labelHeight;contentLeft=x-labelWidth;break;}
return{contentTop,contentLeft,};}
const lightGridColor='rgba(0,0,0,0.2)';const darkGridColor='rgba(0,0,0,0.7)';const gridBackgroundColor='rgba(255, 255, 255, 0.8)';function _drawAxis(context,rulerAtRight,rulerAtBottom){if(window._gridPainted){return;}
window._gridPainted=true;context.save();const pageFactor=pageZoomFactor*pageScaleFactor*emulationScaleFactor;const scrollX=window.scrollX*pageScaleFactor;const scrollY=window.scrollY*pageScaleFactor;function zoom(x){return Math.round(x*pageFactor);}
function unzoom(x){return Math.round(x/pageFactor);}
const width=canvasWidth/pageFactor;const height=canvasHeight/pageFactor;const gridSubStep=5;const gridStep=50;{context.save();context.fillStyle=gridBackgroundColor;if(rulerAtBottom){context.fillRect(0,zoom(height)-15,zoom(width),zoom(height));}else{context.fillRect(0,0,zoom(width),15);}
context.globalCompositeOperation='destination-out';context.fillStyle='red';if(rulerAtRight){context.fillRect(zoom(width)-15,0,zoom(width),zoom(height));}else{context.fillRect(0,0,15,zoom(height));}
context.restore();context.fillStyle=gridBackgroundColor;if(rulerAtRight){context.fillRect(zoom(width)-15,0,zoom(width),zoom(height));}else{context.fillRect(0,0,15,zoom(height));}}
context.lineWidth=1;context.strokeStyle=darkGridColor;context.fillStyle=darkGridColor;{context.save();context.translate(-scrollX,0.5-scrollY);const maxY=height+unzoom(scrollY);for(let y=2*gridStep;y<maxY;y+=2*gridStep){context.save();context.translate(scrollX,zoom(y));context.rotate(-Math.PI/2);context.fillText(y,2,rulerAtRight?zoom(width)-7:13);context.restore();}
context.translate(0.5,-0.5);const maxX=width+unzoom(scrollX);for(let x=2*gridStep;x<maxX;x+=2*gridStep){context.save();context.fillText(x,zoom(x)+2,rulerAtBottom?scrollY+zoom(height)-7:scrollY+13);context.restore();}
context.restore();}
{context.save();if(rulerAtRight){context.translate(zoom(width),0);context.scale(-1,1);}
context.translate(-scrollX,0.5-scrollY);const maxY=height+unzoom(scrollY);for(let y=gridStep;y<maxY;y+=gridStep){context.beginPath();context.moveTo(scrollX,zoom(y));const markLength=(y%(gridStep*2))?5:8;context.lineTo(scrollX+markLength,zoom(y));context.stroke();}
context.strokeStyle=lightGridColor;for(let y=gridSubStep;y<maxY;y+=gridSubStep){if(!(y%gridStep)){continue;}
context.beginPath();context.moveTo(scrollX,zoom(y));context.lineTo(scrollX+gridSubStep,zoom(y));context.stroke();}
context.restore();}
{context.save();if(rulerAtBottom){context.translate(0,zoom(height));context.scale(1,-1);}
context.translate(0.5-scrollX,-scrollY);const maxX=width+unzoom(scrollX);for(let x=gridStep;x<maxX;x+=gridStep){context.beginPath();context.moveTo(zoom(x),scrollY);const markLength=(x%(gridStep*2))?5:8;context.lineTo(zoom(x),scrollY+markLength);context.stroke();}
context.strokeStyle=lightGridColor;for(let x=gridSubStep;x<maxX;x+=gridSubStep){if(!(x%gridStep)){continue;}
context.beginPath();context.moveTo(zoom(x),scrollY);context.lineTo(zoom(x),scrollY+gridSubStep);context.stroke();}
context.restore();}
context.restore();}
function doReset(){document.getElementById('tooltip-container').removeChildren();document.getElementById('grid-label-container').removeChildren();window._gridPainted=false;}
function parseHexa(hexa){return hexa.match(/#(\w\w)(\w\w)(\w\w)(\w\w)/).slice(1).map(c=>parseInt(c,16)/255);}
function formatColor(hexa,colorFormat){if(colorFormat==='rgb'){const[r,g,b,a]=parseHexa(hexa);return`rgb(${(r * 255).toFixed()} ${(g * 255).toFixed()} ${(b * 255).toFixed()}${
        a === 1 ? '' : ' / ' + Math.round(a * 100) / 100})`;}
if(colorFormat==='hsl'){const[h,s,l,a]=rgbaToHsla(parseHexa(hexa));return`hsl(${Math.round(h * 360)}deg ${Math.round(s * 100)} ${Math.round(l * 100)}${
        a === 1 ? '' : ' / ' + Math.round(a * 100) / 100})`;}
if(hexa.endsWith('FF')){return hexa.substr(0,7);}
return hexa;}
function computeIsLargeFont(contrast){const boldWeights=new Set(['bold','bolder','600','700','800','900']);const fontSizePx=parseFloat(contrast.fontSize.replace('px',''));const isBold=boldWeights.has(contrast.fontWeight);const fontSizePt=fontSizePx*72/96;if(isBold){return fontSizePt>=14;}
return fontSizePt>=18;}
function _getElementLayoutType(highlight){if(highlight.gridInfo&&highlight.gridInfo.length){return'grid';}
return null;}
function _createElementDescription(highlight){const{elementInfo,colorFormat}=highlight;const elementInfoElement=createElement('div','element-info');const elementInfoHeaderElement=elementInfoElement.createChild('div','element-info-header');const layoutType=_getElementLayoutType(highlight);if(layoutType){elementInfoHeaderElement.createChild('div',`element-layout-type ${layoutType}`);}
const descriptionElement=elementInfoHeaderElement.createChild('div','element-description monospace');const tagNameElement=descriptionElement.createChild('span','material-tag-name');tagNameElement.textContent=elementInfo.tagName;const nodeIdElement=descriptionElement.createChild('span','material-node-id');const maxLength=80;nodeIdElement.textContent=elementInfo.idValue?'#'+elementInfo.idValue.trimEnd(maxLength):'';nodeIdElement.classList.toggle('hidden',!elementInfo.idValue);const classNameElement=descriptionElement.createChild('span','material-class-name');if(nodeIdElement.textContent.length<maxLength){classNameElement.textContent=(elementInfo.className||'').trimEnd(maxLength-nodeIdElement.textContent.length);}
classNameElement.classList.toggle('hidden',!elementInfo.className);const dimensionsElement=elementInfoHeaderElement.createChild('div','dimensions');dimensionsElement.createChild('span','material-node-width').textContent=Math.round(elementInfo.nodeWidth*100)/100;dimensionsElement.createTextChild('\u00d7');dimensionsElement.createChild('span','material-node-height').textContent=Math.round(elementInfo.nodeHeight*100)/100;const style=elementInfo.style||{};let elementInfoBodyElement;if(elementInfo.isLockedAncestor){addTextRow('Showing the locked ancestor','');}
const color=style['color'];if(color&&color!=='#00000000'){addColorRow('Color',color,colorFormat);}
const fontFamily=style['font-family'];const fontSize=style['font-size'];if(fontFamily&&fontSize!=='0px'){addTextRow('Font',`${fontSize} ${fontFamily}`);}
const bgcolor=style['background-color'];if(bgcolor&&bgcolor!=='#00000000'){addColorRow('Background',bgcolor,colorFormat);}
const margin=style['margin'];if(margin&&margin!=='0px'){addTextRow('Margin',margin);}
const padding=style['padding'];if(padding&&padding!=='0px'){addTextRow('Padding',padding);}
const cbgColor=elementInfo.contrast?elementInfo.contrast.backgroundColor:null;const hasContrastInfo=color&&color!=='#00000000'&&cbgColor&&cbgColor!=='#00000000';if(elementInfo.showAccessibilityInfo){addSection('Accessibility');if(hasContrastInfo){addContrastRow(style['color'],elementInfo.contrast);}
addTextRow('Name',elementInfo.accessibleName);addTextRow('Role',elementInfo.accessibleRole);addIconRow('Keyboard-focusable',elementInfo.isKeyboardFocusable?'a11y-icon a11y-icon-ok':'a11y-icon a11y-icon-not-ok');}
function ensureElementInfoBody(){if(!elementInfoBodyElement){elementInfoBodyElement=elementInfoElement.createChild('div','element-info-body');}}
function addSection(name){ensureElementInfoBody();const rowElement=elementInfoBodyElement.createChild('div','element-info-row element-info-section');const nameElement=rowElement.createChild('div','section-name');nameElement.textContent=name;rowElement.createChild('div','separator-container').createChild('div','separator');}
function addRow(name,rowClassName,valueClassName){ensureElementInfoBody();const rowElement=elementInfoBodyElement.createChild('div','element-info-row');if(rowClassName){rowElement.classList.add(rowClassName);}
const nameElement=rowElement.createChild('div','element-info-name');nameElement.textContent=name;rowElement.createChild('div','element-info-gap');return rowElement.createChild('div',valueClassName||'');}
function addIconRow(name,value){addRow(name,'','element-info-value-icon').createChild('div',value);}
function addTextRow(name,value){addRow(name,'','element-info-value-text').createTextChild(value);}
function addColorRow(name,color,colorFormat){const valueElement=addRow(name,'','element-info-value-color');const swatch=valueElement.createChild('div','color-swatch');const inner=swatch.createChild('div','color-swatch-inner');inner.style.backgroundColor=color;valueElement.createTextChild(formatColor(color,colorFormat));}
function addContrastRow(fgColor,contrast){const ratio=contrastRatio(parseHexa(fgColor),parseHexa(contrast.backgroundColor));const threshold=computeIsLargeFont(contrast)?3.0:4.5;const valueElement=addRow('Contrast','','element-info-value-contrast');const sampleText=valueElement.createChild('div','contrast-text');sampleText.style.color=fgColor;sampleText.style.backgroundColor=contrast.backgroundColor;sampleText.textContent='Aa';const valueSpan=valueElement.createChild('span');valueSpan.textContent=Math.round(ratio*100)/100;valueElement.createChild('div',ratio<threshold?'a11y-icon a11y-icon-warning':'a11y-icon a11y-icon-ok');}
return elementInfoElement;}
function _drawElementTitle(highlight,bounds){const tooltipContainer=document.getElementById('tooltip-container');tooltipContainer.removeChildren();_createMaterialTooltip(tooltipContainer,bounds,_createElementDescription(highlight),true);}
function _createMaterialTooltip(parentElement,bounds,contentElement,withArrow){const tooltipContainer=parentElement.createChild('div');const tooltipContent=tooltipContainer.createChild('div','tooltip-content');tooltipContent.appendChild(contentElement);const titleWidth=tooltipContent.offsetWidth;const titleHeight=tooltipContent.offsetHeight;const arrowHalfWidth=8;const pageMargin=2;const arrowWidth=arrowHalfWidth*2;const arrowInset=arrowHalfWidth+2;const containerMinX=pageMargin+arrowInset;const containerMaxX=canvasWidth-pageMargin-arrowInset-arrowWidth;const boundsAreTooNarrow=bounds.maxX-bounds.minX<arrowWidth+2*arrowInset;let arrowX;if(boundsAreTooNarrow){arrowX=(bounds.minX+bounds.maxX)*0.5-arrowHalfWidth;}else{const xFromLeftBound=bounds.minX+arrowInset;const xFromRightBound=bounds.maxX-arrowInset-arrowWidth;if(xFromLeftBound>containerMinX&&xFromLeftBound<containerMaxX){arrowX=xFromLeftBound;}else{arrowX=Number.constrain(containerMinX,xFromLeftBound,xFromRightBound);}}
const arrowHidden=!withArrow||arrowX<containerMinX||arrowX>containerMaxX;let boxX=arrowX-arrowInset;boxX=Number.constrain(boxX,pageMargin,canvasWidth-titleWidth-pageMargin);let boxY=bounds.minY-arrowHalfWidth-titleHeight;let onTop=true;if(boxY<0){boxY=Math.min(canvasHeight-titleHeight,bounds.maxY+arrowHalfWidth);onTop=false;}else if(bounds.minY>canvasHeight){boxY=canvasHeight-arrowHalfWidth-titleHeight;}
const includes=boxX>=bounds.minX&&boxX+titleWidth<=bounds.maxX&&boxY>=bounds.minY&&boxY+titleHeight<=bounds.maxY;const overlaps=boxX<bounds.maxX&&boxX+titleWidth>bounds.minX&&boxY<bounds.maxY&&boxY+titleHeight>bounds.minY;if(overlaps&&!includes){tooltipContent.style.display='none';return;}
tooltipContent.style.top=boxY+'px';tooltipContent.style.left=boxX+'px';tooltipContent.style.setProperty('--arrow-visibility',(arrowHidden||includes)?'hidden':'visible');if(arrowHidden){return;}
tooltipContent.style.setProperty('--arrow',onTop?'var(--arrow-down)':'var(--arrow-up)');tooltipContent.style.setProperty('--shadow-direction',onTop?'var(--shadow-up)':'var(--shadow-down)');tooltipContent.style.setProperty('--arrow-top',(onTop?titleHeight-1:-arrowHalfWidth)+'px');tooltipContent.style.setProperty('--arrow-left',(arrowX-boxX)+'px');}
function _drawRulers(context,bounds,rulerAtRight,rulerAtBottom,color,dash){context.save();const width=canvasWidth;const height=canvasHeight;context.strokeStyle=color||'rgba(128, 128, 128, 0.3)';context.lineWidth=1;context.translate(0.5,0.5);if(dash){context.setLineDash([3,3]);}
if(rulerAtRight){for(const y in bounds.rightmostXForY){context.beginPath();context.moveTo(width,y);context.lineTo(bounds.rightmostXForY[y],y);context.stroke();}}else{for(const y in bounds.leftmostXForY){context.beginPath();context.moveTo(0,y);context.lineTo(bounds.leftmostXForY[y],y);context.stroke();}}
if(rulerAtBottom){for(const x in bounds.bottommostYForX){context.beginPath();context.moveTo(x,height);context.lineTo(x,bounds.topmostYForX[x]);context.stroke();}}else{for(const x in bounds.topmostYForX){context.beginPath();context.moveTo(x,0);context.lineTo(x,bounds.topmostYForX[x]);context.stroke();}}
context.restore();}
function buildPath(commands,bounds){let commandsIndex=0;function extractPoints(count){const points=[];for(let i=0;i<count;++i){const x=Math.round(commands[commandsIndex++]*emulationScaleFactor);bounds.maxX=Math.max(bounds.maxX,x);bounds.minX=Math.min(bounds.minX,x);const y=Math.round(commands[commandsIndex++]*emulationScaleFactor);bounds.maxY=Math.max(bounds.maxY,y);bounds.minY=Math.min(bounds.minY,y);bounds.leftmostXForY[y]=Math.min(bounds.leftmostXForY[y]||Number.MAX_VALUE,x);bounds.rightmostXForY[y]=Math.max(bounds.rightmostXForY[y]||Number.MIN_VALUE,x);bounds.topmostYForX[x]=Math.min(bounds.topmostYForX[x]||Number.MAX_VALUE,y);bounds.bottommostYForX[x]=Math.max(bounds.bottommostYForX[x]||Number.MIN_VALUE,y);points.push(x,y);}
return points;}
const commandsLength=commands.length;const path=new Path2D();while(commandsIndex<commandsLength){switch(commands[commandsIndex++]){case'M':path.moveTo.apply(path,extractPoints(1));break;case'L':path.lineTo.apply(path,extractPoints(1));break;case'C':path.bezierCurveTo.apply(path,extractPoints(3));break;case'Q':path.quadraticCurveTo.apply(path,extractPoints(2));break;case'Z':path.closePath();break;}}
path.closePath();return path;}
function drawPath(context,commands,fillColor,outlineColor,bounds){context.save();const path=buildPath(commands,bounds);if(fillColor){context.fillStyle=fillColor;context.fill(path);}
if(outlineColor){context.lineWidth=2;context.strokeStyle=outlineColor;context.stroke(path);}
context.restore();return path;}
function emptyBounds(){const bounds={minX:Number.MAX_VALUE,minY:Number.MAX_VALUE,maxX:Number.MIN_VALUE,maxY:Number.MIN_VALUE,leftmostXForY:{},rightmostXForY:{},topmostYForX:{},bottommostYForX:{}};return bounds;}
function _drawLayoutGridHighlight(highlight,context){const gridBounds=emptyBounds();const gridPath=buildPath(highlight.gridBorder,gridBounds);if(highlight.gridHighlightConfig.gridBorderColor){context.save();context.translate(0.5,0.5);context.lineWidth=0;if(highlight.gridHighlightConfig.gridBorderDash){context.setLineDash([3,3]);}
context.strokeStyle=highlight.gridHighlightConfig.gridBorderColor;context.stroke(gridPath);context.restore();}
if(highlight.gridHighlightConfig.cellBorderColor){const rowBounds=emptyBounds();const columnBounds=emptyBounds();const rowPath=buildPath(highlight.rows,rowBounds);const columnPath=buildPath(highlight.columns,columnBounds);context.save();context.translate(0.5,0.5);if(highlight.gridHighlightConfig.cellBorderDash){context.setLineDash([3,3]);}
context.lineWidth=0;context.strokeStyle=highlight.gridHighlightConfig.cellBorderColor;context.save();context.stroke(rowPath);context.restore();context.save();context.stroke(columnPath);context.restore();context.restore();if(highlight.gridHighlightConfig.showGridExtensionLines){_drawRulers(context,rowBounds,false,false,highlight.gridHighlightConfig.cellBorderColor,highlight.gridHighlightConfig.cellBorderDash);_drawRulers(context,rowBounds,true,true,highlight.gridHighlightConfig.cellBorderColor,highlight.gridHighlightConfig.cellBorderDash);_drawRulers(context,columnBounds,false,false,highlight.gridHighlightConfig.cellBorderColor,highlight.gridHighlightConfig.cellBorderDash);_drawRulers(context,columnBounds,true,true,highlight.gridHighlightConfig.cellBorderColor,highlight.gridHighlightConfig.cellBorderDash);}}
_drawGridGap(context,highlight.rowGaps,highlight.gridHighlightConfig.rowGapColor,highlight.gridHighlightConfig.rowHatchColor,true);_drawGridGap(context,highlight.columnGaps,highlight.gridHighlightConfig.columnGapColor,highlight.gridHighlightConfig.columnHatchColor);drawGridNumbers(highlight,gridBounds);}
function _drawGridGap(context,gapCommands,gapColor,hatchColor,flipDirection){if(!gapColor&&!hatchColor){return;}
context.save();context.translate(0.5,0.5);context.lineWidth=0;const bounds=emptyBounds();const path=buildPath(gapCommands,bounds);if(gapColor){context.fillStyle=gapColor;context.fill(path);}
if(hatchColor){hatchFillPath(context,path,bounds,10,hatchColor,flipDirection);}
context.restore();}
function hatchFillPath(context,path,bounds,delta,color,flipDirection){const dx=bounds.maxX-bounds.minX;const dy=bounds.maxY-bounds.minY;context.rect(bounds.minX,bounds.minY,dx,dy);context.save();context.clip(path);context.setLineDash([5,3]);const majorAxis=Math.max(dx,dy);context.strokeStyle=color;if(flipDirection){for(let i=-majorAxis;i<majorAxis;i+=delta){context.beginPath();context.moveTo(bounds.maxX-i,bounds.minY);context.lineTo(bounds.maxX-dy-i,bounds.maxY);context.stroke();}}else{for(let i=-majorAxis;i<majorAxis;i+=delta){context.beginPath();context.moveTo(i+bounds.minX,bounds.minY);context.lineTo(dy+i+bounds.minX,bounds.maxY);context.stroke();}}
context.restore();}
function drawHighlight(highlight,context){context=context||window.context;context.save();const bounds=emptyBounds();for(let paths=highlight.paths.slice();paths.length;){const path=paths.pop();context.save();drawPath(context,path.path,path.fillColor,path.outlineColor,bounds);if(paths.length){context.globalCompositeOperation='destination-out';drawPath(context,paths[paths.length-1].path,'red',null,bounds);}
context.restore();}
context.restore();context.save();const rulerAtRight=highlight.paths.length&&highlight.showRulers&&bounds.minX<20&&bounds.maxX+20<canvasWidth;const rulerAtBottom=highlight.paths.length&&highlight.showRulers&&bounds.minY<20&&bounds.maxY+20<canvasHeight;if(highlight.showRulers){_drawAxis(context,rulerAtRight,rulerAtBottom);}
if(highlight.paths.length){if(highlight.showExtensionLines){_drawRulers(context,bounds,rulerAtRight,rulerAtBottom);}
if(highlight.elementInfo){_drawElementTitle(highlight,bounds);}}
if(highlight.gridInfo){for(const grid of highlight.gridInfo){_drawLayoutGridHighlight(grid,context);}}
context.restore();return{bounds:bounds};}
const style=`
body {
  --arrow-width: 15px;
  --arrow-height: 8px;
  --shadow-up: 5px;
  --shadow-down: -5px;
  --shadow-direction: var(--shadow-up);
  --arrow-down: polygon(0 0, 100% 0, 50% 100%);
  --arrow-up: polygon(50% 0, 0 100%, 100% 100%);
}

.px {
  color: rgb(128, 128, 128);
}

#element-title {
  position: absolute;
  z-index: 10;
}

/* Material */

.tooltip-content {
  position: absolute;
  z-index: 10;
  -webkit-user-select: none;
}

.tooltip-content {
  background-color: white;
  padding: 5px 8px;
  border: 1px solid white;
  border-radius: 3px;
  box-sizing: border-box;
  min-width: 100px;
  max-width: min(300px, 100% - 4px);
  z-index: 1;
  background-clip: padding-box;
  will-change: transform;
  text-rendering: optimizeLegibility;
  pointer-events: none;
  filter: drop-shadow(0 2px 4px rgba(0,0,0,0.35));
}

.tooltip-content::after {
  content: "";
  background: white;
  width: var(--arrow-width);
  height: var(--arrow-height);
  clip-path: var(--arrow);
  position: absolute;
  top: var(--arrow-top);
  left: var(--arrow-left);
  visibility: var(--arrow-visibility);
}

.element-info-section {
  margin-top: 12px;
  margin-bottom: 6px;
}

.section-name {
  color: #333;
  font-weight: 500;
  font-size: 10px;
  text-transform: uppercase;
  letter-spacing: .05em;
  line-height: 12px;
}

.element-info {
  display: flex;
  flex-direction: column;
}

.element-info-header {
  display: flex;
  align-items: start;
}

.element-info-body {
  display: flex;
  flex-direction: column;
  padding-top: 2px;
  margin-top: 2px;
}

.element-info-row {
  display: flex;
  line-height: 19px;
}

.separator-container {
  display: flex;
  align-items: center;
  flex: auto;
  margin-left: 7px;
}

.separator {
  border-top: 1px solid #ddd;
  width: 100%;
}

.element-info-name {
  flex-shrink: 0;
  color: #666;
}

.element-info-gap {
  flex: auto;
}

.element-info-value-color {
  display: flex;
  color: rgb(48, 57, 66);
  margin-left: 10px;
  align-items: baseline;
}

.element-info-value-contrast {
  display: flex;
  align-items: center;
  text-align: right;
  color: rgb(48, 57, 66);
  margin-left: 10px;
}

.element-info-value-contrast .a11y-icon {
  margin-left: 8px;
}

.element-info-value-icon {
  display: flex;
  align-items: center;
}

.element-info-value-text {
  text-align: right;
  color: rgb(48, 57, 66);
  margin-left: 10px;
  align-items: baseline;
  overflow: hidden;
  text-overflow: ellipsis;
  white-space: nowrap;
}

.color-swatch {
  display: flex;
  margin-right: 2px;
  width: 10px;
  height: 10px;
  background-image: url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAwAAAAMCAIAAADZF8uwAAAAGUlEQVQYV2M4gwH+YwCGIasIUwhT25BVBADtzYNYrHvv4gAAAABJRU5ErkJggg==);
  line-height: 10px;
}

.color-swatch-inner {
  flex: auto;
  border: 1px solid rgba(128, 128, 128, 0.6);
}

.element-layout-type {
  margin-right: 10px;
  width: 16px;
  height: 16px;
}

.element-layout-type.grid {
  background-image: url('data:image/svg+xml,<svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg"><rect x="2.5" y="2.5" width="4" height="4" stroke="%231A73E8"/><rect x="9.5" y="2.5" width="4" height="4" stroke="%231A73E8"/><rect x="9.5" y="9.5" width="4" height="4" stroke="%231A73E8"/><rect x="2.5" y="9.5" width="4" height="4" stroke="%231A73E8"/></svg>');
}

.element-description {
  flex: 1 1;
  font-weight: bold;
  word-wrap: break-word;
  word-break: break-all;
}

.dimensions {
  color: hsl(0, 0%, 45%);
  text-align: right;
  margin-left: 10px;
}

.material-node-width {
  margin-right: 2px;
}

.material-node-height {
  margin-left: 2px;
}

.material-tag-name {
  /* Keep this in sync with inspectorSyntaxHighlight.css (--dom-tag-name-color) */
  color: rgb(136, 18, 128);
}

.material-class-name, .material-node-id {
  /* Keep this in sync with inspectorSyntaxHighlight.css (.webkit-html-attribute-value) */
  color: rgb(26, 26, 166);
}

.contrast-text {
  width: 16px;
  height: 16px;
  text-align: center;
  line-height: 16px;
  margin-right: 8px;
  border: 1px solid rgba(0, 0, 0, 0.1);
  padding: 0 1px;
}

.a11y-icon {
  width: 16px;
  height: 16px;
  background-repeat: no-repeat;
  display: inline-block;
}

.a11y-icon-not-ok {
  background-image: url('data:image/svg+xml,<svg fill="none" viewBox="0 0 18 18" xmlns="http://www.w3.org/2000/svg"><path d="m9 1.5c-4.14 0-7.5 3.36-7.5 7.5s3.36 7.5 7.5 7.5 7.5-3.36 7.5-7.5-3.36-7.5-7.5-7.5zm0 13.5c-3.315 0-6-2.685-6-6 0-1.3875.4725-2.6625 1.2675-3.675l8.4075 8.4075c-1.0125.795-2.2875 1.2675-3.675 1.2675zm4.7325-2.325-8.4075-8.4075c1.0125-.795 2.2875-1.2675 3.675-1.2675 3.315 0 6 2.685 6 6 0 1.3875-.4725 2.6625-1.2675 3.675z" fill="%239e9e9e"/></svg>');
}

.a11y-icon-warning {
  background-image: url('data:image/svg+xml,<svg fill="none" viewBox="0 0 18 18" xmlns="http://www.w3.org/2000/svg"><path d="m8.25 11.25h1.5v1.5h-1.5zm0-6h1.5v4.5h-1.5zm.7425-3.75c-4.14 0-7.4925 3.36-7.4925 7.5s3.3525 7.5 7.4925 7.5c4.1475 0 7.5075-3.36 7.5075-7.5s-3.36-7.5-7.5075-7.5zm.0075 13.5c-3.315 0-6-2.685-6-6s2.685-6 6-6 6 2.685 6 6-2.685 6-6 6z" fill="%23e37400"/></svg>');
}

.a11y-icon-ok {
  background-image: url('data:image/svg+xml,<svg fill="none" viewBox="0 0 18 18" xmlns="http://www.w3.org/2000/svg"><path d="m9 1.5c-4.14 0-7.5 3.36-7.5 7.5s3.36 7.5 7.5 7.5 7.5-3.36 7.5-7.5-3.36-7.5-7.5-7.5zm0 13.5c-3.3075 0-6-2.6925-6-6s2.6925-6 6-6 6 2.6925 6 6-2.6925 6-6 6zm-1.5-4.35-1.95-1.95-1.05 1.05 3 3 6-6-1.05-1.05z" fill="%230ca40c"/></svg>');
}

/* Grid row and column labels */
.grid-label-content {
  position: absolute;
  z-index: 10;
  -webkit-user-select: none;
}

.grid-label-content {
  background-color: #1A73E8;
  padding: 2px;
  font-family: Menlo, monospace;
  font-size: 10px;
  min-width: 10px;
  min-height: 15px;
  color: #FFFFFF;
  border: 1px solid white;
  border-radius: 2px;
  box-sizing: border-box;
  z-index: 1;
  background-clip: padding-box;
  will-change: transform;
  pointer-events: none;
  text-align: center;
  display: flex;
  justify-content: center;
  align-items: center;
}

.grid-label-content::before {
  position: absolute;
  z-index: 1;
  pointer-events: none;
  content: "";
  background: #1A73E8;
  width: 3px;
  height: 3px;
  border: 1px solid white;
  border-width: 0 1px 1px 0;
}

.grid-label-content.bottom-mid::before {
  transform: translateY(-1px) rotate(45deg);
  top: 100%;
}

.grid-label-content.top-mid::before {
  transform: translateY(-3px) rotate(-135deg);
  top: 0%;
}

.grid-label-content.left-mid::before {
  transform: translateX(-3px) rotate(135deg);
  left: 0%
}

.grid-label-content.right-mid::before {
  transform: translateX(3px) rotate(-45deg);
  right: 0%;
}

.grid-label-content.right-top::before {
  transform: translateX(3px) translateY(-1px) rotate(-90deg) skewY(30deg);
  right: 0%;
  top: 0%;
}

.grid-label-content.right-bottom::before {
  transform: translateX(3px) translateY(-3px) skewX(30deg);
  right: 0%;
  top: 100%;
}

.grid-label-content.bottom-right::before {
  transform:  translateX(1px) translateY(-1px) skewY(30deg);
  right: 0%;
  top: 100%;
}

.grid-label-content.bottom-left::before {
  transform:  translateX(-1px) translateY(-1px) rotate(90deg) skewX(30deg);
  left: 0%;
  top: 100%;
}

.grid-label-content.left-top::before {
  transform: translateX(-3px) translateY(-1px) rotate(180deg) skewX(30deg);
  left: 0%;
  top: 0%;
}

.grid-label-content.left-bottom::before {
  transform: translateX(-3px) translateY(-3px) rotate(90deg) skewY(30deg);
  left: 0%;
  top: 100%;
}

.grid-label-content.top-right::before {
  transform:  translateX(1px) translateY(-3px) rotate(-90deg) skewX(30deg);
  right: 0%;
  top: 0%;
}

.grid-label-content.top-left::before {
  transform:  translateX(-1px) translateY(-3px) rotate(180deg) skewY(30deg);
  left: 0%;
  top: 0%;
}

@media (forced-colors: active) {
  :root, body {
      background-color: transparent;
      forced-color-adjust: none;
  }
  .tooltip-content {
      border-color: Highlight;
      background-color: Canvas;
      color: Text;
      forced-color-adjust: none;
  }
  .tooltip-content::after {
      background-color: Highlight;
  }
  .color-swatch-inner,
  .contrast-text,
  .separator {
      border-color: Highlight;
  }
  .section-name {
      color: Highlight;
  }
  .dimensions,
  .element-info-name,
  .element-info-value-color,
  .element-info-value-contrast,
  .element-info-value-icon,
  .element-info-value-text,
  .material-tag-name,
  .material-class-name,
  .material-node-id {
      color: CanvasText;
  }
}`;window.setPlatform=function(platform){const styleTag=document.createElement('style');styleTag.innerHTML=style;document.head.append(styleTag);document.body.classList.add('fill');const canvas=document.createElement('canvas');canvas.id='canvas';canvas.classList.add('fill');document.body.append(canvas);const tooltip=document.createElement('div');tooltip.id='tooltip-container';document.body.append(tooltip);const gridLabels=document.createElement('div');gridLabels.id='grid-label-container';document.body.append(gridLabels);setPlatform(platform);};window.reset=function(data){reset(data);doReset();};window.drawHighlight=drawHighlight;window.dispatch=dispatch;}());