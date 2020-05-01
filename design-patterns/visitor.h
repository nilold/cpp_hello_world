#ifndef HELLOWORLD_VISITOR_H
#define HELLOWORLD_VISITOR_H

#include <string>
#include <iostream>

namespace nilolib {

    class BronzeCreditCard;

    class SilverCreditCard;

    class GoldCreditCard;

    class OfferVisitor {
    public:
        virtual void visitBronzeCreditCard(const BronzeCreditCard &card) const = 0;

        virtual void visitSilverCreditCard(const SilverCreditCard &card) const = 0;

        virtual void visitGoldCreditCard(const GoldCreditCard &card) const = 0;
    };

    class CreditCard {
    public:
        virtual std::string getName() const = 0;

        virtual void accept(const OfferVisitor &v) const = 0;
    };

    class BronzeCreditCard : public CreditCard {
    public:
        std::string getName() const override {
            return "Bronze";
        }

        void accept(const OfferVisitor &v) const override {
            v.visitBronzeCreditCard(*this);
        }
    };

    class SilverCreditCard : public CreditCard {
    public:
        std::string getName() const override {
            return "Silver";
        }

        void accept(const OfferVisitor &v) const override {
            v.visitSilverCreditCard(*this);
        }
    };

    class GoldCreditCard : public CreditCard {
    public:
        std::string getName() const override {
            return "Gold";
        }

        void accept(const OfferVisitor &v) const override {
            v.visitGoldCreditCard(*this);
        }
    };

    class GasOfferVisitor : public OfferVisitor {
        void visitBronzeCreditCard(const BronzeCreditCard &card) const override {
            std::cout << "Buying gas with a " << card.getName() << " card" << std::endl;
        }

        void visitSilverCreditCard(const SilverCreditCard &card) const override {
            std::cout << "Buying gas with a " << card.getName() << " card" << std::endl;
        }

        void visitGoldCreditCard(const GoldCreditCard &card) const override {
            std::cout << "Buying gas with a " << card.getName() << " card" << std::endl;
        }

    };

    class HotelOfferVisitor : public OfferVisitor {
        void visitBronzeCreditCard(const BronzeCreditCard &card) const override {
            std::cout << "Booking hotel room with a " << card.getName() << " card" << std::endl;
        }

        void visitSilverCreditCard(const SilverCreditCard &card) const override {
            std::cout << "Booking hotel room with a " << card.getName() << " card" << std::endl;
        }

        void visitGoldCreditCard(const GoldCreditCard &card) const override {
            std::cout << "Booking hotel room with a " << card.getName() << " card" << std::endl;
        }

    };

}

#endif //HELLOWORLD_VISITOR_H
