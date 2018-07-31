    import sys
    
    symbols1 =     [(1,   "I"), (5,   "V"), (10,   "X")]
    symbols10 =    [(10,  "X"), (50,  "L"), (100,  "C")]
    symbols100 =   [(100, "C"), (500, "D"), (1000, "M")]
    
    symList = [symbols1, symbols10, symbols100]
    
    def digitToRomanSym (digit, symList):
        """ Converts a single digit into its roman symbol """
        one =  symList[0][1]
        five = symList[1][1]
        ten =  symList[2][1]
        
        switcher = {
            1: one,
            2: one + one,
            3: one + one + one,
            4: one + five,
            5: five,
            6: five + one,
            7: five + one + one,
            8: five + one + one + one,
            9: one + ten,
        }
        return switcher.get(digit, "")
    
    def getRomanNumerals (n):
        """ Converts a number between 1 and 3999 into Roman numerals """
        maxNumber = symList[-1][-1][0] * 4 - 1 # A symbol can be repeated max 3 times e.g. MMM for 3000
      
        if (n > maxNumber):
            return "Number too big"
        
        if (n == 0):
            return "Number too small"
            
        i = 0
        romanStr = ""
        while (n > 0 and i < len(symList)):
            romanStr = digitToRomanSym(n % 10, symList[i]) + romanStr
            n /= 10
            i += 1
            
        if (n > 0):
            biggestSymbol = symList[-1][-1][1]
            romanStr = (n * biggestSymbol) + romanStr;
    
        return romanStr
    
    if (len(sys.argv) == 2):
        number = int(sys.argv[1])
        print(getRomanNumerals(number))
    else:
        print("Wrong number of arguments")