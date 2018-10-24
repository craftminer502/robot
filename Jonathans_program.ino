#include <ax12.h>  // Dette gør at vi kan bruge kommandoer fra ax12 biblioteket

// -----------------------------------------------------

void setup(){ // Her starter setup (kører 1 gang)
  Serial.begin(9600);
  
  // Knap 1
  pinMode(0, INPUT); 

  
  // Sæt hastighed på motorer
  Serial.println("Setting motor speeds...");
  for(int i = 1; i <= 3; i++){
    ax12SetRegister2(i, 32, 50);
  }
  ax12SetRegister2(4, 32, 120);
  ax12SetRegister2(5, 32, 500);

  // Sæt til startposition
  for(int i = 1; i <= 5; i++){
    SetPosition(i, 512);
    delay(500);
  }
  
}// Her slutter setup


// -----------------------------------------------------


void loop(){ // Her starter loopet (Kører for evigt)

  // Knap 1 starter programmet 
  int startBtn = digitalRead(0); 
  if(startBtn == HIGH){
    
    //  Robotten bevæger sig til disse positioner:
    SetPosition(5, 0);
    delay(1000);
    
    SetPosition(5, 500);
    delay(1000);
    
    SetPosition(1, 400);
    delay(1000);
    
    
  }
}// Her slutter loopet

