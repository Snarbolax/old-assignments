#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BowCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  unsigned int d = barcode/10000;
  d = d%10;
  return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
	unsigned int d = barcode/1000;
	d = d%10;
	return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
	unsigned int d = barcode/100;
	d = d%10;
	return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
	unsigned int d = barcode/10;
	d = d%10;
	return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
	unsigned int d = barcode;
	d = d%10;
	return d;
}

// Constructor for struct Bow
Bow::Bow(string bowColor, string bowShape, string bowTexture,
		 unsigned int barcode):bowColor_(bowColor),bowShape_(bowShape),
				       bowTexture_(bowTexture),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void BowCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string bowColor;
    string bowShape;
    string bowTexture;
    unsigned int barcode;
    while (myfile >> bowColor >> bowShape >> bowTexture >> barcode) {
			if (bowColor.size() > 0)
      	addBow(bowColor, bowShape, bowTexture, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void BowCollection::addBow(string bowColor, string bowShape, string bowTexture, unsigned int barcode) {

	Bow temp(bowColor, bowShape, bowTexture, barcode);
	hT1.insert(barCode, temp);
	hT2.insert(barCode, temp);
	hT3.insert(barCode, temp);
	hT4.insert(barCode, temp);
	hT5.insert(barCode, temp);

}

bool BowCollection::removeBow(unsigned int barcode) {
		
	if (hT1.count(barcode) == 1)
	{
		hT1.erase(barcode);
		hT2.erase(barcode);
		hT3.erase(barcode);
		hT4.erase(barcode);
		hT5.erase(barcode);
		return true;
	}

	return false;

}

unsigned int BowCollection::bestHashing() {

	size_t balance1 = 0;
	size_t balance2 = 0;
	size_t balance3 = 0;
	size_t balance4 = 0;
	size_t balance5 = 0;

	size_t maxtemp = 0;
	size_t mintemp = 0;
	size_t maxtemp2 = 0;
	size_t mintemp2 = 0;
	size_t maxtemp3 = 0;
	size_t mintemp3 = 0;
	size_t maxtemp4 = 0;
	size_t mintemp4 = 0;
	size_t maxtemp5 = 0;
	size_t mintemp5 = 0;

	size_t most_balanced = 0;

	for (size_t i = 0; i < hT1.bucket_count(); i++)
	{
		if (i = 0)
		{
			mintemp = hT1.bucket_size(0);
		}

		if (hT1.bucket_size(i) > maxtemp)
		{
			maxtemp = hT1.bucket_size(i);
		}

		if (hT1.bucket_count() < 10)
		{
			mintemp = 0;
		}
		else if (hT1.bucket_size(i) < mintemp)
		{
			mintemp = hT1.bucket_size(i);
		}
	}

	balance1 = maxtemp - mintemp;

	for (size_t j = 0; j < hT2.bucket_count(); j++)
	{
		if (j = 0)
		{
			mintemp2 = hT2.bucket_size(0);
		}

		if (hT2.bucket_size(j) > maxtemp2)
		{
			maxtemp2 = hT2.bucket_size(j);
		}

		if (hT2.bucket_count() < 10)
		{
			mintemp2 = 0;
		}
		else if (hT2.bucket_size(j) < mintemp2)
		{
			mintemp2 = hT2.bucket_size(j);
		}
	}

	balance2 = maxtemp2 - mintemp2;

	for (size_t k = 0; k < hT3.bucket_count(); k++)
	{
		if (k = 0)
		{
			mintemp3 = hT3.bucket_size(0);
		}

		if (hT3.bucket_size(k) > maxtemp3)
		{
			maxtemp3 = hT3.bucket_size(k);
		}

		if (hT3.bucket_count() < 10)
		{
			mintemp3 = 0;
		}
		else if (hT3.bucket_size(k) < mintemp3)
		{
			mintemp3 = hT3.bucket_size(k);
		}
	}

	balance3 = maxtemp3 - mintemp3;

	for (size_t m = 0; m < hT4.bucket_count(); m++)
	{
		if (m = 0)
		{
			mintemp4 = hT4.bucket_size(0);
		}

		if (hT4.bucket_size(m) > maxtemp4)
		{
			maxtemp4 = hT4.bucket_size(m);
		}

		if (hT4.bucket_count() < 10)
		{
			mintemp4 = 0;
		}
		else if (hT4.bucket_size(m) < mintemp4)
		{
			mintemp4 = hT4.bucket_size(m);
		}
	}

	balance4 = maxtemp4 - mintemp4;

	for (size_t n = 0; n < hT5.bucket_count(); n++)
	{
		if (n = 0)
		{
			mintemp5 = hT5.bucket_size(0);
		}

		if (hT5.bucket_size(n) > maxtemp5)
		{
			maxtemp5 = hT5.bucket_size(n);
		}

		if (hT5.bucket_count() < 10)
		{
			mintemp5 = 0;
		}
		else if (hT5.bucket_size(n) < mintemp5)
		{
			mintemp5 = hT5.bucket_size(n);
		}
	}

	balance5 = maxtemp5 - mintemp5;

	most_balanced = balance1;
	if (most_balanced > balance2)
	{
		most_balanced = balance2;
	}
	if (most_balanced > balance3)
	{
		most_balanced = balance3;
	}
	if (most_balanced > balance4)
	{
		most_balanced = balance4;
	}
	if (most_balanced > balance5)
	{
		most_balanced = balance5;
	}

	if (most_balanced == balance1)
	{
		return hT1;
	}
	else if (most_balanced == balance2)
	{
		return hT2;
	}
	else if (most_balanced == balance3)
	{
		return hT3;
	}
	else if (most_balanced == balance4)
	{
		return hT4;
	}
	else
	{
		return hT5;
	}

}

// ALREADY COMPLETED
size_t BowCollection::size() {
	if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size()))
  	throw std::length_error("Hash table sizes are not the same");
	return hT1.size();
}
