/* 
 * File:   MAX7219.h
 * Author: davem
 *
 * Created on February 26, 2023, 10:15 AM
 */

#ifndef MAX7219_H
#define	MAX7219_H

#ifdef	__cplusplus
extern "C" {
#endif

void SPI_init(void) ;
void SPI_write(uint8_t send) ;
void MAX7219_init(char noChips) ;
void MAX7219_config(char chip) ;
void MAX7219_write(char regName,uint8_t data,char chip) ;
void MAX7219_displayText(char* text) ;
void MAX7219_dropText(char* text) ;
void MAX7219_NoOperation(void) ;

//----------------------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* MAX7219_H */

