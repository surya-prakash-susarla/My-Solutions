class AuthenticationManager {
 public:
  AuthenticationManager(int timeToLive) { ttl = timeToLive; }

  void generate(string tokenId, int currentTime) {
    tokens[tokenId] = currentTime + ttl;
  }

  void renew(string tokenId, int currentTime) {
    if (not tokens.contains(tokenId))
      return;
    if (tokens[tokenId] <= currentTime)
      return;
    tokens[tokenId] = currentTime + ttl;
  }

  int countUnexpiredTokens(int currentTime) {
    int answer = 0;
    for (auto i : tokens)
      if (i.second > currentTime)
        answer++;
    return answer;
  }

  int ttl;
  map<string, int> tokens;
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
