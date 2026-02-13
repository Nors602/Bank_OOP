#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
    static float ReadAmount()
    {
        cout << "\nEnter Amount : ";
        return clsInputValidate::ReadFloatNumber();
    }

    static clsCurrency ReadCurrencyCode()
    {
        string CurrencyCode;

        cout << "\nEnter Currency Code : ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "Currency Code does not exist, enter another one : ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        return clsCurrency::FindByCode(CurrencyCode);
    }

    static void PrintCurrencyCard(const clsCurrency& Currency)
    {
        cout << "\n\tCurrency Card\n";
        cout << "_________________________\n";
        cout << "Country : " << Currency.Country() << endl;
        cout << "Code    : " << Currency.CurrencyCode() << endl;
        cout << "Name    : " << Currency.CurrencyName() << endl;
        cout << "Rate 1$ : " << Currency.Rate() << endl;
        cout << "_________________________\n";
    }

    static float ConvertFromCurrencyToUSD(float Amount, const clsCurrency& FromCurrency)
    {
        return Amount / FromCurrency.Rate();
    }

    static float ConvertFromUSDToCurrency(float Amount, const clsCurrency& ToCurrency)
    {
        return Amount * ToCurrency.Rate();
    }

    static char ReadAnswer()
    {
        char Answer;

        do
        {
            cout << "\nDo you want to perform another currency calculation? [Y/N] : ";
            cin >> Answer;

        } while (tolower(Answer) != 'y' && tolower(Answer) != 'n');

        return tolower(Answer);
    }

public:

    static void ShowCurrencyCalculatorScreen()
    {
      

        char Answer;

        do
        {
            _DrawScreenHeader("\tCurrency Calculator Screen");

            cout << "\nFrom Currency:\n";
            clsCurrency FromCurrency = ReadCurrencyCode();
            PrintCurrencyCard(FromCurrency);

            float Amount = ReadAmount();
            float AmountInUSD = ConvertFromCurrencyToUSD(Amount, FromCurrency);

            cout << "\nAmount in USD : " << AmountInUSD << " $\n";

            cout << "\nTo Currency:\n";
            clsCurrency ToCurrency = ReadCurrencyCode();
            PrintCurrencyCard(ToCurrency);

            float FinalAmount = ConvertFromUSDToCurrency(AmountInUSD, ToCurrency);

            cout << "\nAmount in " << ToCurrency.CurrencyCode()
                << " : " << FinalAmount << " " << ToCurrency.CurrencyCode() << "\n";

            Answer = ReadAnswer();

            system("cls");

        } while (Answer != 'n');
    }
};
