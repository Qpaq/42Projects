var streaming = false;
var video = document.querySelector('#video');
var cover = document.querySelector('#cover');
var canvas = document.querySelector('#canvas');
var photo = document.querySelector('#photo');
var startbutton = document.querySelector('#startbutton');
var inputImgData = document.querySelector("#imgData");
var width = 500;
var height = 375;

var imgInp =  document.querySelector("#imgInp");
var myImg =  document.querySelector("#myImg");

navigator.getUserMedia = navigator.getUserMedia || navigator.webkitGetUserMedia || navigator.mozGetUserMedia || navigator.msGetUserMedia || navigator.oGetUserMedia;

if (navigator.getUserMedia) navigator.getUserMedia({video: true}, handleVideo, videoError);

function handleVideo(stream) {
	video.src = window.URL.createObjectURL(stream);
}

function videoError(e) {}

startbutton.addEventListener('click', function(ev) {
	takepicture();
}, false);


function takepicture() {
	canvas.width = width;
	canvas.height = height;
	if (video.style.display != "none")
    	canvas.getContext('2d').drawImage(video, 0, 0, width, height);
	else
		canvas.getContext('2d').drawImage(myImg, 0, 0, width, height);

	var data = canvas.toDataURL('image/png');

	inputImgData.value = data;
	photo.setAttribute('src', data);
}

function check() {
	var ele = document.getElementsByName('choice');
	var flag=0;
	for(var i=0; i < ele.length; i++) {
		if (ele[i].checked) flag = 1;
	}
	if (flag == 1) {
		var button = document.querySelector('#startbutton');
		button.disabled=false;
		button.style.backgroundColor = "green";
		button.value = "  Take a picture  ";
	}
}

imgInp.addEventListener('change', function(ev) {
	if (this.files && this.files[0]) {
		var reader = new FileReader();
		reader.onload = imageIsLoaded;
		reader.readAsDataURL(this.files[0]);
	}
});

function imageIsLoaded(e) {
   myImg.setAttribute('src', e.target.result);
   myImg.style.display = 'block';
   video.style.display = 'none';
};
