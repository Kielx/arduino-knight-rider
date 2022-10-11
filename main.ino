int brightness = 0;
int pins[] = {3,5,6,9,10,11};

// set pins array to output mode
void setPinsToOutput() {
	for (int i=0; i < (sizeof(pins) / sizeof(pins[0])); i++){
	pinMode(pins[i], OUTPUT);
    }
}

void writeToPins(int brightness){
	for (int i=0; i < (sizeof(pins) / sizeof(pins[0])); i++){
	analogWrite(pins[i], brightness);
    }
}

void setThreeLights(int position){
  if (position == 0){
  	analogWrite(pins[position], 255);
  	analogWrite(pins[position+1], 255/4);
  }
  if (position > 0 && position < 6) {
  	analogWrite(pins[position-1], 255/4);
  	analogWrite(pins[position], 255);
  	analogWrite(pins[position+1], 255/4);
  }
  if (position == 6){
  	analogWrite(pins[position], 255);
  	analogWrite(pins[position-1], 255/4);
  }
  
}


void setup()
{
  setPinsToOutput();
}

void loop()
{
  for (int i=0; i<7; i++){
  	setThreeLights(i);
    delay(50);
    writeToPins(0);
  }
  writeToPins(0);
  delay(500);
  for (int i=6; i>=0; i--){
  	setThreeLights(i);
    delay(50);
    writeToPins(0);
  }
  writeToPins(0);
  delay(500);
}
