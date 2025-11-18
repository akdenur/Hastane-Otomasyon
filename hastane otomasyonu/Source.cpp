#include<iostream> 
#include<fstream>
#include<string> 
#include <stdio.h> 

using namespace std;

int main() {

	string isminiz;
	string soyisminiz;
	string tc_kimlik_numaranýz;
	string telefon_numaranýz;
	string yaþýnýz;
	string sigorta_durumunuz;
	string ödeme_tutarýnýz;

	string randevu_trh;
	string randevu_saati;
	string anabilim_dalý;
	
    
	int istek, k = 1;
	string yanýt = "evet";

	do 
	{
		cout << "NE YAPMAK ISTERSINIZ ?" << endl;
		cout << endl;
		cout << "1) Hasta Kaydi Olusturmak " << endl;
		cout << "2) Randevu Kaydi  Olusturmak " << endl;
		cout << "3) Hasta Muayene Kaydi " << endl;

		cout << endl;
		cin >> istek; 
	} while (istek != 1 && istek != 2 && istek != 3);
	{
		if (istek == 1)
		{
			system("cls");
			cout << " 1- Hasta Kaydi Olusturmak" << endl;

			ofstream evrakyaz;

			evrakyaz.open("hasta.txt", ios::app);

			do
			{

				cout << "\n Hasta'nin tc kimlik numarasý :"; cin >> tc_kimlik_numaranýz;
				cout << "\n Hasta'nin ismi :"; cin >> isminiz;
				cout << "\n Hasta'nin soyismi :"; cin >> soyisminiz;
				cout << "\n Hasta'nin yaþý :"; cin >> yaþýnýz;
				cout << "\n Hasta'nin telefon numarasi :"; cin >> telefon_numaranýz;
				cout << "\n Hasta Sigorta Durumu :"; cin >> sigorta_durumunuz;
				cout << endl;

				if (sigorta_durumunuz == "var") {
					cout << "Hatane ücreti yoktur" << endl;
				}
				else if (sigorta_durumunuz == "yok") {
					cout << "\n Hasta'nin ödediði ücret" << endl; cin >> ödeme_tutarýnýz;
					cout << "Hatanýn ödediði ücret miktarý : " << ödeme_tutarýnýz << "TL" << endl;
				}
				else {
					cout << "Hastane kaydý yoktur" << endl;
				}

				evrakyaz << "\n" << tc_kimlik_numaranýz << " " << isminiz << " " << soyisminiz << " " << yaþýnýz << " " << telefon_numaranýz << " " << sigorta_durumunuz;


				cout << "Hasta kayýdý olusturuldu" << endl;
				cout << "Kayit olusturmaya devam etmek istermisiniz?(e/h) " << endl; cin >> yanýt;
			} while (yanýt == "evet");

			if (yanýt == "hayýr")
				evrakyaz.close();
		}
	}
		if (istek == 2)
		{
			system("cls"); 
			cout <<  "2 - Randevu kayidi olusturmak" << endl;
			string tc_no;
			cout << "Hasta Tc Numarasini Giriniz:"; cin >> tc_no;
			ifstream evrakoku("hasta.txt");
			ofstream evrakyaz("hasta.txt", ios::app);

			int gcc = 0;
			while (!evrakoku.eof())
			{
				evrakoku >> tc_kimlik_numaranýz >> isminiz >> soyisminiz >> yaþýnýz >> telefon_numaranýz >> sigorta_durumunuz >> ödeme_tutarýnýz;
		
				if (tc_kimlik_numaranýz == tc_no) 
				{
					cout << "Hasta Bigileri...\n";
					cout << " Hasta Tc :" << tc_kimlik_numaranýz << endl;
					cout << "Hasta Adi :" << isminiz << endl;
					cout << "Hastan Soyadi :" << soyisminiz << endl;
					cout << "Hasta Dogum Taihi :" << yaþýnýz << endl;
					cout << "Hasta Telefon Numarasi :" << telefon_numaranýz << endl;
					cout << "Hasta Sigorta Durumu :" << sigorta_durumunuz;
					cout << "\n Hasta'nin ödediði ücret" << endl; cin >> ödeme_tutarýnýz;
					
					
					gcc = 1;
	}
			}
			if (gcc == 0)
			{
				cout << "Hasta Kaydi Bulunmamaktadir Hasta Kaydi Yapiniz... ";
				cout << "\n Hasta Tc No Giriniz.......:"; cin >> tc_no;
				cout << "\n Hasta Adi Giriniz.........:"; cin >> isminiz;
				cout << "\n Hasta Soyadi Giriniz......:"; cin >> soyisminiz;
				cout << "\n Hasta Yaþýný giriniz......:"; cin >> yaþýnýz;
				cout << "\n Hasta Telefon Numarasi....:"; cin >> telefon_numaranýz;
				cout << "\n Hasta Sigorta durumu?"; cin >> sigorta_durumunuz;
				cout << "\n Hastanýn ödediði ücret"; cin >> ödeme_tutarýnýz;
				

				evrakyaz << tc_kimlik_numaranýz << " " << isminiz << " " << soyisminiz << " " << yaþýnýz << " " << telefon_numaranýz << " " << sigorta_durumunuz <<ödeme_tutarýnýz<< "\n";
				cout << "Hasta Kayidi Tamamlandi." << endl;
			}
			cout << "Randevu Ýstiyor Musunuz..?(e/h)" << endl;
			cin >> yanýt;

			if (yanýt == "evet")
			{
				evrakoku.close();
				evrakyaz.close();
				ofstream evrakyaz;
				evrakyaz.open("randevu.txt", ios::app);

				cout << "\n Randevu Bilgileri \n";
				cout << "\n Randevu Tarihi :"; cin >> randevu_trh;
				cout << "\n Randevu Saat :"; cin >> randevu_saati;
				cout << "\n Anabilim dali :"; cin >> anabilim_dalý;
				cout << "\n Anabilim dali :"; cin >> anabilim_dalý;
				cout << "\n Anabilim dali3 :"; cin >> anabilim_dalý;

				evrakyaz << tc_no << " " << randevu_trh << " " << randevu_saati<<" " << anabilim_dalý << " " << " " << "- " << "-" << " " << "-" << "\n";
				cout << "Randevu Kayit Isleminiz Gerceklesmistir..." << endl;
				evrakyaz.close();
			}
			else
				cout << "Isleminiz Gerceklesmistir..." << endl;
		}
		if (istek == 3)
		{
			string tc_arama;
			system("cls");
			cout << " Hasta Muayene Kayidi " << endl;
			ifstream evrakoku("hasta.txt");

			cout << "Muayene Yapilacak Hastanýn Tc'si......:"; cin >> tc_arama;
			int gcc = 0;
			while (!(evrakoku.eof()))
			{
				evrakoku >> tc_kimlik_numaranýz >> isminiz >> soyisminiz >> yaþýnýz >> telefon_numaranýz >> sigorta_durumunuz>>ödeme_tutarýnýz;
				if (tc_kimlik_numaranýz == tc_arama)
				{
					cout << "  Hasta Bilgileri  " << endl;

					cout << "Hasta Tc :" << tc_arama << endl;
					cout << "hastanin Adi :" << isminiz << endl;
					cout << "Hasta Soyadi : " << soyisminiz << endl;
					cout << "Hasta Dogum Tarihi :" << yaþýnýz << endl;
					cout << "Hasta Telefon Numarasi :" << telefon_numaranýz << endl;
					cout << "Hasta Sigorta durumu :" << sigorta_durumunuz << endl;
					cout << "odemis oldugunuz tutar" << ödeme_tutarýnýz << endl;


					evrakoku.close();

					ifstream evrakoku("randevu.txt");
					ofstream evrakyaz("randevu.txt", ios::app);
					while (!(evrakoku.eof()))  
					{
						evrakoku >> tc_kimlik_numaranýz >> randevu_trh >> randevu_saati >> anabilim_dalý;
						if (tc_arama == tc_kimlik_numaranýz)
						{
							do
							{
							    cout <<  "Randevu Bilgileri " << endl;

								cout << "Hasta Tc :" << tc_arama << endl;
								cout << "Randevu Tarihi :" << randevu_trh << endl;
								cout << "Randevu Saati :" << randevu_saati << endl;
								cout << " Randevu için aldýðý anablim dalý :" << anabilim_dalý << "\n";

								cout << "Muayene Kayýdý tamamlandi." << endl;
								cout << "Kayit Yapma Devam Edecek Misiniz.....?(e/h) " << endl; cin >> yanýt;
							} while (!(yanýt == "hayýr")); 
						}
					}

					evrakyaz.close();
					
					cout << "Dosya Yazimi Tamamlandi. " << endl;
					gcc = 1;
					break;
				}
				if (gcc == 0)
					cout << "Böyle Bir Kayit Bulunmamaktadir....." << endl;
			}
		}
		 system("pause");

		return 0; 
	}




