#define variationTime 2
#define lambda 8

#define minConsigne 25
#define maxConsigne 75

#define timeStep variationTime/nPoint
#define nPoint 20*variationTime

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define Periode = ((1/490)*1000) // Période du signal à la fréquence donnée 490Hz. = Freq PWM Arduino



struct dataStruct
{
  int deltaPwm;
  float pointTime;
  int pwmStart;
  float X;
  int i;
};

