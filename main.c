#include <mega32.h> 
#include <delay.h> 
#include <alcd.h>
// 7-segment flash unsigned char 
data[5] = { 0x40, 0x06, 0x5b, 0x4f,  0x66,  }; 
int flag_menu = 0; int flag_eb = 0; int t_menu = 0; int t_eb = 0; // Define states 
enum type { state1, state2, state3, state4, sub1, sub2, sub3, sub4, } mode; 
void main(void) {
lcd_init(16); 
DDRD = 0xFF; // 7-segment output 
PORTD = 0x00; 
DDRA = 0x00; // Button input 
PORTA = 0x03; // Pull-up on PA0 and PA1 
DDRC = 0xFF; //the led + relay
while (1) {
delay_ms(1); 
t_menu++;
t_eb++;
PORTC=0X00; 
switch (mode) { 
case state1: 
  PORTC=0X00; 
  PORTD = data[0]; 
  lcd_gotoxy(0, 0); 
  lcd_putsf("relay_1 <<"); 
  lcd_gotoxy(0, 1); lcd_putsf("relay_2");
if ( flag_menu == 0) { 
  if (PINA.0 == 0){ 
    flag_menu = 1; 
    t_menu = 0; PORTC=0X00; } }
else { 
  if (t_menu >29){ 
    if (PINA.0 == 0) t_menu = 0; 
    else{ mode=state2; 
         lcd_clear(); 
         flag_menu=0; 
         PORTC=0X00; } } } 
  if(flag_eb==0){ 
    if(PINA.1==0){ 
      flag_eb=1; t_eb=0; } } 
  else{ if(t_eb>29){ 
    if(PINA.1==0) t_eb=0; 
    else{ mode=sub1; lcd_clear(); flag_eb=0; } } }
break;
case state2:
  lcd_gotoxy(0, 0);
  lcd_putsf("relay_1");
  lcd_gotoxy(0, 1); 
  lcd_putsf("relay_2 <<");
  PORTC=0X00; 
  if ( flag_menu == 0) { 
    if (PINA.0 == 0){
      flag_menu = 1; 
      t_menu = 0; 
      PORTC=0X00; } } 
  else { if (t_menu >29){ 
    if (PINA.0 == 0) 
      t_menu = 0; 
    else{ mode=state3; 
         lcd_clear(); 
         flag_menu=0; PORTC=0X00; } } }
if(flag_eb==0){ 
  if(PINA.1==0){ 
    flag_eb=1; t_eb=0; } } 
else{ if(t_eb>29){ 
  if(PINA.1==0) t_eb=0; 
  else{ mode=sub2; lcd_clear(); flag_eb=0; } } } 
  break;
case state3: 
  lcd_gotoxy(0, 0); 
  lcd_putsf("relay_3 <<"); 
  lcd_gotoxy(0, 1); 
  lcd_putsf("relay_4 "); 
  PORTC=0X00; 
  if ( flag_menu == 0) { 
    if (PINA.0 == 0){ 
      flag_menu = 1; 
      t_menu = 0; 
      PORTC=0X00; } } 
  else { if (t_menu >29){ 
    if (PINA.0 == 0) 
      t_menu = 0; 
    else{ mode=state4; 
         lcd_clear(); 
         flag_menu=0; 
         PORTC=0X00; } } }
if(flag_eb==0){ 
  if(PINA.1==0){
    flag_eb=1; t_eb=0; } } 
else{ if(t_eb>29){ 
  if(PINA.1==0) 
  t_eb=0;
  else{ mode=sub3; 
       lcd_clear(); 
       flag_eb=0; } } } 
  break;
case state4: 
lcd_gotoxy(0, 0); 
lcd_putsf("relay_3 "); 
lcd_gotoxy(0, 1); 
lcd_putsf("relay_4 << "); 
PORTC=0X00; 
if ( flag_menu == 0) { 
  if (PINA.0 == 0){ 
    flag_menu = 1; 
    t_menu = 0; PORTC=0X00; } } 
else { if (t_menu >29 ){ 
  if (PINA.0 == 0) 
    t_menu = 0; 
  else{ mode=state1; 
       lcd_clear(); 
       flag_menu=0; PORTC=0X00; } } }
if(flag_eb==0){ 
  if(PINA.1==0){ 
    flag_eb=1; 
    t_eb=0; } } 
else{ if(t_eb>29){ 
  if(PINA.1==0) 
    t_eb=0;
  else{ mode=sub4; 
       lcd_clear(); 
       flag_eb=0; } } } 
  break;
case sub1: 
  lcd_gotoxy(0, 0); 
  lcd_putsf("relay_1 is on "); 
  PORTC=0X01; 
  PORTD=data[1]; 
  if(flag_eb==0){
    if(PINA.1 == 0){ flag_eb=1; t_eb=0; } }
  else{ if(t_eb>29){ if(PINA.1 == 0)
    t_eb=0; 
  else{ 
    mode=state1; 
    lcd_clear(); 
    flag_eb=0;
    PORTD = data[0]; 
    PORTC=0X00; } } } 
  break;
case sub2: 
  lcd_gotoxy(0, 0); 
  lcd_putsf("relay_2 is on "); 
  PORTC=0X02; PORTD=data[2];
  if(flag_eb==0){ if(PINA.1 == 0){
    flag_eb=1; t_eb=0; } } 
  else{ if(t_eb>29){ if(PINA.1 == 0) 
    t_eb=0; 
  else{ mode=state2; 
  lcd_clear(); flag_eb=0; PORTD = data[0]; PORTC=0X00; } } } 
  break;
case sub3: 
  lcd_gotoxy(0, 0); 
  lcd_putsf("relay_3 is on "); 
  PORTC=0X04; PORTD=data[3]; 
  if(flag_eb==0){ 
    if(PINA.1 == 0){ flag_eb=1; t_eb=0; } } 
  else{ if(t_eb>29){ if(PINA.1 == 0) t_eb=0;
  else{ mode=state3;
       lcd_clear(); 
       flag_eb=0; PORTD = data[0]; 
       PORTC=0X00; } } }
  break;
case sub4: 
  lcd_gotoxy(0, 0); 
  lcd_putsf("relay_4 is on "); 
  PORTC=0X08; PORTD=data[4]; 
  if(flag_eb==0){ 
    if(PINA.1 == 0){ flag_eb=1; t_eb=0; } } 
  else{ if(t_eb>29){ if(PINA.1 == 0) t_eb=0; 
  else{ mode=state4; lcd_clear(); 
       flag_eb=0; PORTD = data[0]; PORTC=0X00; } } } 
  break; 
} //switch 
}//while 
}//main















