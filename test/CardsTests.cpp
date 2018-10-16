#include <gtest/gtest.h>
#include "Cards.hpp"
#include <stdexcept>

struct CardsTests : public ::testing::Test
{
    json dataJson = R"({
                    "0" : "Zobowiązany jesteś zmodernizować swoje miasto, płacisz za każdy dom 80 $,za każdy hotel 230 $",
                    "1" : "Remontujesz swoje domy. Płacisz do banku za każdy dom 50 $, za każdy hotel 200 $.",
                    "2" : "Wracasz do Madrytu.",
                    "3" : "Mandat za szybko jazdę. Płacisz 30 $.",
                    "4" : "Cofasz się o trzy pola.",
                    "5" : "Wracasz na start.",
                    "6" : "Rozwiązałeś dobrze krzyżówkę. Jako 1 nagrodę otrzymujesz 200 $.",
                    "7" : "Idziesz do więzienia. Nie przechodzisz przez start. Nie otrzymujesz premii 400 $.",
                    "8" : "Płacisz opłatę za szkołę 300 $.",
                    "9" : "Idziesz do Neapolu. Jeżeli przechodzisz przez start otrzymujesz 400 $.",
                    "10": "Piłeś w czasie pracy, płacisz karę 40 $.",
                    "11": "Wracasz do Brukseli. Jeżeli przechodzi przez start otrzymujesz 400 $.",
                    "12": "Bank wypłaca Ci procenty w wysokości 100 $.",
                    "13": "Idziesz do Kolei Wschodnich. Jeżeli przechodzisz przez start otrzymujesz 400 $.",
                    "14": "Bank wpłaca Ci należne odsetki w wysokości 300 $.",
                    "15": "Wychodzisz wolny z więzienia. Kartę należy zachować do wykorzystania lub sprzedania."
                })"_json;
    Cards redCards{"red", dataJson};
};

TEST_F(CardsTests, check_if_color_of_reCards_is_red)
{
    ASSERT_EQ("red", redCards.getColor());
}

TEST_F(CardsTests, check_if_call_getOneCard_out_of_range_will_throw_exception)
{
    ASSERT_ANY_THROW(redCards.getOneCard(83));
}

TEST_F(CardsTests, check_if_2th_card_is_Wracasz_do_Madrytu)
{
    ASSERT_EQ("Wracasz do Madrytu.", redCards.getOneCard(2));
}
