// Lines 3-121 not coded by me

var canvas = document.getElementById('whiteboard');
if(canvas){var context= canvas.getContext('2d');}

var tool;
tool = new tool_pencil();

var color = "#ffffff";
var lineWidth = 5;

document.body.addEventListener('touchmove',function(event){ event.preventDefault(); },false);

function listen(){
    canvas = document.getElementById('whiteboard'); 
    if(canvas){
        context= canvas.getContext('2d');
        context.fillStyle = color;  
        context.lineWidth = lineWidth;
        context.fillRect(0, 0, canvas.width, canvas.height);
        iphone = ((window.navigator.userAgent.match('iPhone'))||(window.navigator.userAgent.match('iPod')))?true:false;
        ipad = (window.navigator.userAgent.match('iPad'))?true:false;
        if(iphone||ipad){
            canvas.addEventListener('touchstart', ev_canvas, false);
            canvas.addEventListener('touchend', ev_canvas, false);
            canvas.addEventListener('touchmove', ev_canvas, false);
        }
        else{
            canvas.addEventListener('mousedown', ev_canvas, false);
            canvas.addEventListener('mousemove', ev_canvas, false);
            canvas.addEventListener('mouseup',   ev_canvas, false);
        }
    }
}

function tool_pencil () {
    var tool = this;
    this.started = false;
    this.mousedown = function (ev) {
        context.beginPath();
        context.moveTo(ev._x, ev._y);
        tool.started = true;
    };

    this.mousemove = function (ev) {
        if (tool.started) {
            context.lineTo(ev._x, ev._y);
            context.stroke();
        }
    };

    this.mouseup = function (ev) {
        if (tool.started) {
            tool.mousemove(ev);
            tool.started = false;
            //img_update();
        }
    };
    this.touchstart = function (ev) {
        ev.preventDefault();
        context.beginPath();
        context.moveTo(ev._x, ev._y);
        tool.started = true;
    };

    this.touchmove = function (ev) {
        ev.preventDefault();
        if (tool.started) {
            context.lineTo(ev._x, ev._y);
            context.stroke();
        }
    };

    this.touchend = function (ev) {
        ev.preventDefault();
        if (tool.started) {
            tool.started = false;
        }
    };
}

// The general-purpose event handler. This function just determines the mouse position relative to the canvas element.
function ev_canvas (ev) {
    iphone = ((window.navigator.userAgent.match('iPhone'))||(window.navigator.userAgent.match('iPod')))?true:false;
    ipad = (window.navigator.userAgent.match('iPad'))?true:false;
    if (((iphone)||(ipad))&&(ev.touches[0])){ //iPad
        ev._x = ev.touches[0].clientX;
        ev._y = ev.touches[0].clientY;
    }
    else if (ev.layerX || ev.layerX == 0) { // Firefox
        ev._x = ev.layerX;
        ev._y = ev.layerY;
    }
    else if (ev.offsetX || ev.offsetX == 0) { // Opera
        ev._x = ev.offsetX;
        ev._y = ev.offsetY;
    }
  // Call the event handler of the tool.
    var func = tool[ev.type];
    if (func) {
        func(ev);
    }
}

function clearImage(){
    var yes=confirm('Clear drawing?');
    if(yes){
        context.clearRect(0, 0, canvas.width, canvas.height);
        context.fillStyle = "rgb(255,255,255)";  
        context.fillRect(0, 0, canvas.width, canvas.height);
    }
}

// https://stackoverflow.com/questions/10673122/how-to-save-canvas-as-an-image-with-canvas-todataurl
function saveImage(data, filename = 'whiteboard.jpg') {
    var a = document.createElement('a');
    a.href = data;
    a.download = filename;
    document.body.appendChild(a);
    a.click();
}

// -- My code begins now --
var exitWarning = false;

window.onbeforeunload = function() {
  if (exitWarning) {
    return true;
  }
};

document.querySelector("#whiteboard").addEventListener("mouseup",
  function() {
    exitWarning = true;
  }
)

// May not be exact but good enough for informal purposes
function approximateHeaderHeight(height) {
  if (height > 720) {
    return 80;
  } else if (height > 480) {
    return 132.875;
  } else {
    return 194.875;
  }
}

const windowHeight = window.outerHeight;

const availableWidth = window.innerWidth - 60;
const availableHeight = window.innerHeight - 60 - approximateHeaderHeight(windowHeight) - 60;

document.querySelector("#whiteboard").setAttribute("width", `${availableWidth}px`);
document.querySelector("#whiteboard").setAttribute("height", `${availableHeight}px`);

document.querySelector("#whiteboard-clear").addEventListener("click", clearImage);
document.querySelector("#whiteboard-save").addEventListener("click", function(e) {
  var canvas = document.querySelector('#whiteboard');
  var dataURL = canvas.toDataURL("image/jpeg", 1.0);
  saveImage(dataURL, 'whiteboard.jpg');
});

document.querySelector("#whiteboard-pensize-var").addEventListener("change", function() {
  context.lineWidth = document.querySelector("#whiteboard-pensize-var").value;
});

document.querySelector("#whiteboard-color-var").addEventListener("change", function() {
  context.strokeStyle = document.querySelector("#whiteboard-color-var").value;
});

document.querySelector("#whiteboard-bgcolor-var").addEventListener("change", function() {
  context.fillStyle = document.querySelector("#whiteboard-bgcolor-var").value;
  context.fillRect(0, 0, canvas.width, canvas.height);
});

listen();