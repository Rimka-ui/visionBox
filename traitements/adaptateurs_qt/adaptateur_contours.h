#ifndef ADAPTATEUR_CONTOURS_H
#define ADAPTATEUR_CONTOURS_H

#endif // ADAPTATEUR_CONTOURS_H
QPixmap CvMatToQPixmap(Mat matimage);// l'appel à cette fonction permettra de transformer notre image Mat en image Pixmap utilisable par Qt pour l'affichage dans un widget Qt
void onSliderValueChanged_1(int value);// Cette fonction nous permettra de controler le niveau de contour avec un slider que l'on créer dans qt
// nous utiliseront la fonction "connect"; pour faire un SIGNAL and SLOT sur la variable qui contrôle le contour dans l'appel à la fonction Canny de Opencv
