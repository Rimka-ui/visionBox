Mat image=imread("chemin de l'image",);
Mat input=image.clone();
Mat blurImg;
blur(input,blurImg,Size(5,5));
Mat Gray;
cvtColor(input,Gray,COLOR_RGB2Gray);
Canny(blurImg,Gray,50,150);
