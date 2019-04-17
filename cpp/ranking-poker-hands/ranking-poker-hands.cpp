#include <math.h>
using namespace std;

struct PokerHand {
  const int RANK = 0;
  const int SUIT = 1;
  long cards[5][2];
  string ranks;
  
  PokerHand (const string pokerhand) {
    for (long i = 0; i < 5; i++) {
      cards[i][RANK] = pokerhand[i * 3] - '0';
      cards[i][SUIT] = pokerhand[i * 3 + 1];
      switch (cards[i][RANK] + '0') {
        case 'T':
          cards[i][RANK] = 10;
          break;
        case 'J':
          cards[i][RANK] = 11;
          break;
        case 'Q':
          cards[i][RANK] = 12;
          break;
        case 'K':
          cards[i][RANK] = 13;
          break;
        case 'A':
          cards[i][RANK] = 14;
          break;
      }
      ranks.append(1, cards[i][RANK]);
    }
  }
  
  long flush() const {
    if (cards[0][SUIT] == cards[1][SUIT] && cards[0][SUIT] == cards[2][SUIT] &&
        cards[0][SUIT] == cards[3][SUIT] && cards[0][SUIT] == cards[4][SUIT]) {
      return junkValue();
    }
    return 0;
  }
  
  long straight() const {
    if (junkValue() == 1405040302) {
      return 5; // Low ace straight (1-5)
    }
    long high = max(max(max(max(cards[0][RANK], cards[1][RANK]), cards[2][RANK]), cards[3][RANK]), cards[4][RANK]);
    for (long i = 0; i < 4; i++) {
      if (ranks.find(high - i - 1) == string::npos) {
        return 0;
      }
    }
    return high;
  }
  
  long fourKind() const {
    for (auto card : cards) {
      if (count(ranks.begin(), ranks.end(), card[RANK]) == 4) {
        return card[RANK] * 100 + junkValue();
      }
    }
    return 0;
  }
  
  long threeKind() const {
    for (auto card : cards) {
      if (count(ranks.begin(), ranks.end(), card[RANK]) == 3) {
        return card[RANK] * 10000 + junkValue();
      }
    }
    return 0;
  }
  
  long pair() const {
    for (auto card : cards) {
      if (count(ranks.begin(), ranks.end(), card[RANK]) == 2) {
        return card[RANK] * 1000000 + junkValue();
      }
    }
    return 0;
  }
  
  long twoPair() const {
    long firstPair = pair();
    for (auto card : cards) {
      if (count(ranks.begin(), ranks.end(), card[RANK]) == 2 && (firstPair != card[RANK] * 1000000 + junkValue())) {
        return max(firstPair, card[RANK]) * 10000 + min(firstPair, card[RANK]) * 100 + junkValue();
      }
    }
    return 0;
  }
  
  long fullHouse() const {
    if (threeKind() && pair()) {
      return threeKind() * 100 + pair();
    }
    return 0;
  }
  
  long straightFlush() const {
    return straight() ? flush() : 0;
  }
  
  long junkValue() const {
    long index = 0;
    long value = 0;
    for (long i = 2; i <= 14; i++) {
      if (count(ranks.begin(), ranks.end(), i) == 1) {
        value += i * pow(100, index);
        index++;
      }
    }
    return value;
  }
};

enum class Result { Win, Loss, Tie };

Result compare (const PokerHand &player, const PokerHand &opponent) {
  long score = player.straightFlush() - opponent.straightFlush();
  if (player.straightFlush() || score) {
    return score > 0 ? Result::Win : (score < 0 ? Result::Loss : Result::Tie);
  }
  score = player.fourKind() - opponent.fourKind();
  if (player.fourKind() || score) {
    return score > 0 ? Result::Win : (score < 0 ? Result::Loss : Result::Tie);
  }
  score = player.fullHouse() - opponent.fullHouse();
  if (player.fullHouse() || score) {
    return score > 0 ? Result::Win : (score < 0 ? Result::Loss : Result::Tie);
  }
  score = player.flush() - opponent.flush();
  if (player.flush() || score) {
    return score > 0 ? Result::Win : (score < 0 ? Result::Loss : Result::Tie);
  }
  score = player.straight() - opponent.straight();
  if (player.straight() || score) {
    return score > 0 ? Result::Win : (score < 0 ? Result::Loss : Result::Tie);
  }
  score = player.threeKind() - opponent.threeKind();
  if (player.threeKind() || score) {
    return score > 0 ? Result::Win : (score < 0 ? Result::Loss : Result::Tie);
  }
  score = player.twoPair() - opponent.twoPair();
  if (player.twoPair() || score) {
    return score > 0 ? Result::Win : (score < 0 ? Result::Loss : Result::Tie);
  }
  score = player.pair() - opponent.pair();
  if (player.pair() || score) {
    return score > 0 ? Result::Win : (score < 0 ? Result::Loss : Result::Tie);
  }
  score = player.junkValue() - opponent.junkValue();
  return score > 0 ? Result::Win : (score < 0 ? Result::Loss : Result::Tie);
}
