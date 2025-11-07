#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
static int myrandom()
{
    int x = time(0);
    srand(x);
    return rand() % 3;
}

int main()
{
    const string parola = "abcd1234";
    const string kullanici_adi = "username123";
    bool dogrulama = false;
    string input1;
    string input2;
    int secim;
    int faizmiktar = 0;
    bool faiz = false;
    int sene = 0;
    float miktar;
    float para = 400;
    char currency = '$';
    double faiz_oranlari[3] = {1.1, 1.5, 2.3}; // her sene rastgele biri seçilir
    int randomint;                             // Math.random(0,3)

    cout << ".......Banka sistemimize hos geldiniz......" << endl
         << "secebilecekleriniz: " << endl;
    cout << "1-\t giris yap \n2-\t para yatir \n3-\t para  cek \n4-\t faize koy(her islem = 1 yil) \n5-\t exit \n6-\t bakiyemi goster\n7-\t faizi çek" << endl;
    cin >> secim;
    while (true)
    {
        switch (secim) {
        

        case 1:{
        
        

            if (faiz)
            {
                randomint = myrandom();
                para += faiz_oranlari[randomint] * faizmiktar;
            }
            sene++;
            cout << "kullanici adinizi giriniz: " << flush;
            cin >> input1;
            cout << "şifrenizi giriniz: " << flush;
            cin >> input2;
            if (input1 == kullanici_adi && input2 == parola)
            {
                cout << "giris basarili";
                dogrulama = true;
                sene++;
                break;
            }
                else{
                
                    cout << "kullanici adi ya da şifre hatali" << endl;
                    sene++;
                    break;
                }
            
        }

        case 2:{
        if(!dogrulama){
            cout << "once giriş yapiniz" << endl;
            break;
        }

            if (faiz)
            {
                randomint = myrandom();
                para += faiz_oranlari[randomint] * faizmiktar;
                sene++;
                
            }
            cout << "yatirmak istediğiniz miktar nedir: " << flush;
                cin >> miktar;
                para += miktar;
                cout << "para yatirildi yeni miktar: " << para << endl;
        }

        case 3:{
        if(!dogrulama){
            cout << "once giriş yapiniz" << endl;
            break;
        }

            if (faiz)
            {
                randomint = myrandom();
                para += faiz_oranlari[randomint] * faizmiktar;
            }
            cout << "çekmek istediginiz para miktari nedir: " << flush;
                cin >> miktar;
                if (miktar > para || miktar < 0)
                {
                    cout << "hatali miktar girdiniz";
                    break;
                }
                para -= miktar;
                cout << "para cekildi yeni miktar: " << para << endl;
                break;
            
        }

        case 4:{
        if(!dogrulama){
            cout << "once giriş yapiniz" << endl;
            break;
        }

            if (faiz)
            {
                randomint = myrandom();
                para += faiz_oranlari[randomint] * faizmiktar;
            }
            cout << "faize koymak istediğiniz miktari giriniz: " << flush;
            cin >> faizmiktar;
            if (faizmiktar > para || faizmiktar < 0)
            {
                cout << "hatali miktar girdiniz";
                break;
            }

                faiz = true;
                para -= faizmiktar;
                cout << faizmiktar << " kadar para faize konuldu" << endl;
                break;
            
        }

        case 6:{
        if(!dogrulama){
            cout << "once giriş yapiniz" << endl;
            break;
        }

            if (faiz)
            {
                randomint = myrandom();
                para += faiz_oranlari[randomint] * faizmiktar;
                
            }
            cout << "hesabinizdaki bakiye: " << para << endl;
            break;
        }

        case 7: {
        if(!dogrulama){
            cout << "once giriş yapiniz" << endl;
            break;
        }

            cout << "fazidan ne kadar para çekmek istiyorsun: " << flush;
            cin >> miktar;
            if (miktar > faizmiktar || miktar < 0)
            {
                cout << "hatali miktar girdiniz";
                break;
            }
                faizmiktar -= miktar;
                para += miktar;
                cout << "işlem tamamlandi guncel faizdeki para: " << faizmiktar << "kullanilabilir bakiye: " << para << endl;
                break;
            
        }

        case 5:{
            cout << "çikiliyor..." << endl;
            return 0;
        }

        default:
            cout << "yanliş seçim yaptiniz";
        }
        cout << "1-\t giris yap \n2-\t para yatir \n3-\t para  cek \n4-\t faize koy(her islem = 1 yil) \n5-\t exit \n6-\t bakiyemi goster\n7-\t faizi çek" << endl;
        cin >> secim;
    }
    
}
