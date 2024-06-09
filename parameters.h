/*#define VARIATION_TIME 2
#define LAMBDA 8

#define MIN_CONSIGNE 25
#define MAX_CONSIGNE 75

#define TIME_STEP VARIATION_TIME/nPoint
#define nPoint 20*VARIATION_TIME*/

const float VARIATION_TIME = 2.0; // de 0% à 100%
const int LAMBDA = 8;             // Profil de courbe

const int MIN_CONSIGNE = 25; // Bridage de vitesse minimale
const int MAX_CONSIGNE = 75; // Bridage de vitesse maximale

// const int nPoint = 20 * VARIATION_TIME *;
const float TIME_STEP = 0.05; // Temps entre 2 point de calcul

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define Periode = ((1 / 490) * 1000) // Période du signal à la fréquence donnée 490Hz. = Freq PWM Arduino

struct dataStruct
{
  int consigne;      // Consigne en % 0-100
  int nPoint;      // Nombre de points pour le calcul de la courbe
  int deltaPwm;    // ecart en PWM de la consigne initiale à la consigne finale
  float pointTime; // Temps au point calculé
  int pwmStart;    // PWM de départ
  float X;         // de -05 à 05 pour le calcul de la courbe
  int i;           // Pour le bouclage i max = nPoint
};
