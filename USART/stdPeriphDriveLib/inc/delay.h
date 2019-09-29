#ifndef DELAY_H
#define DELAY_H

#define SYSCLK 72

void delay_init( void );
void delay_ms( unsigned short int mstime );
void delay_us( unsigned int ustime );
void delay_se( unsigned char setime );

#endif
