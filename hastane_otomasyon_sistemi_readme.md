# 🏥 Hastane Otomasyon Sistemi (C++)

Bu proje, C++ ile geliştirilmiş konsol tabanlı basit bir hastane yönetim ve otomasyon sistemidir. Uygulama, dosya işleme (file I/O) yöntemlerini kullanarak hastaların kayıtlarını, sigorta durumlarını ve randevu bilgilerini metin belgeleri (`.txt`) üzerinde kalıcı olarak saklar.

## 🚀 Özellikler

Uygulama temel olarak 3 ana modülden oluşmaktadır:

1. **Hasta Kaydı Oluşturma:**
   * Hastanın TC Kimlik No, Ad, Soyad, Yaş, Telefon ve Sigorta durumu bilgilerini alır.
   * Sigortası olmayan hastalar için muayene ücreti girişi sağlar.
   * Girilen bilgileri `hasta.txt` dosyasına kaydeder.

2. **Randevu Kaydı Oluşturma:**
   * TC Kimlik Numarası ile sistemde (hasta.txt) arama yapar.
   * Hasta kayıtlıysa bilgilerini ekrana getirir ve hangi anabilim dalından, hangi tarih ve saatte randevu alınacağını sorar.
   * Hasta kayıtlı değilse, önce yeni kayıt oluşturulmasını sağlar.
   * Randevu verilerini `randevu.txt` dosyasına kaydeder.

3. **Hasta Muayene Kaydı:**
   * TC Kimlik Numarası üzerinden hastanın genel bilgilerini ve ödediği tutarı listeler.
   * `randevu.txt` dosyasını okuyarak hastanın geçmiş/mevcut randevu detaylarını (Tarih, Saat, Anabilim Dalı) ekranda gösterir.

## 🛠️ Kullanılan Teknolojiler
* **Dil:** C++
* **Kütüphaneler:** `<iostream>`, `<fstream>` (Dosya okuma/yazma), `<string>`
* **Veri Saklama:** `.txt` tabanlı yerel dosya sistemi

## 💻 Kurulum ve Kullanım

Projeyi kendi bilgisayarınızda çalıştırmak için aşağıdaki adımları izleyebilirsiniz:

1. Proje dosyalarını bilgisayarınıza indirin.
2. C++ derleyicisi (örneğin GCC, MinGW) veya bir IDE (Visual Studio, Dev-C++, Code::Blocks vb.) kullanarak kaynak kod dosyasını (`main.cpp`) derleyin.
3. Derlenen `.exe` dosyasını çalıştırın.
4. Program çalıştığında otomatik olarak `hasta.txt` ve `randevu.txt` dosyalarını bulunduğu dizinde oluşturacak veya var olan dosyaların üzerine veri ekleyecektir (Append mode).

## 📂 Dosya Yapısı

* `main.cpp`: Uygulamanın ana kaynak kodu.
* `hasta.txt`: Hasta bilgilerinin boşluklarla ayrılarak tutulduğu metin belgesi (Program tarafından otomatik oluşturulur).
* `randevu.txt`: Randevu detaylarının tutulduğu metin belgesi (Program tarafından otomatik oluşturulur).

## ⚠️ Önemli Notlar
* Program verileri okurken boşluk karakterini (` `) ayırıcı olarak kullanmaktadır. Bu nedenle Ad, Soyad veya Anabilim Dalı gibi girişlerde boşluk bırakmamaya (örneğin "Dahiliye" veya "Goz_Hastaliklari") dikkat edilmelidir.
* Ekran temizleme işlemleri için `system("cls")` kullanılmıştır, bu komut Windows işletim sistemlerinde çalışır.