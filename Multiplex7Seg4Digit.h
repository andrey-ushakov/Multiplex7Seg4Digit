#ifndef Multiplex7Seg4Digit_h
#define Multiplex7Seg4Digit_h


#define DIG_1  0b00000010
#define DIG_2  0b00010000
#define DIG_3  0b00100000
#define DIG_4  0b01000000
			     
#define ZERO   0b00101000
#define ONE    0b11101101
#define TWO    0b00110100
#define THREE  0b10100100
#define FOUR   0b11100001
#define FIVE   0b10100010
#define SIX    0b00100010
#define SEVEN  0b11101100
#define EIGHT  0b00100000
#define NINE   0b10100000


class Multiplex7Seg4Digit {
	public:
		/*
			Constructor. Takes 3 ardiono pins connected to multiplexor
		*/
		Multiplex7Seg4Digit(const int latchPin, const int clockPin, const int dataPin);

		/*
			Clear diaplay
		*/
		void clear();

		/* 
			Display number. A 1-digit number displays in the 4rd position.
			A 2-digit number displays starting from 3rd position etc.
		*/
		void displayNum(int num);


  private:
		int _latchPin;
		int _clockPin;
		int _dataPin;
		static const int ARR_POS[4];		// initialized in .cpp file
		static const int ARR_NUM[10];		// initialized in .cpp file
		int _num;							// curent number on display
		bool _isNumDefined = false;			// true if we have to display _num

		/*
			Show decimal in given position [0..3]
		*/
		void displayDecimal(int dec, int pos);
		
		/*
			MsTimer2 callback function
		*/
		static void update();
};

#endif