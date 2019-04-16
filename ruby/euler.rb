
def problem1
    sum = 0
    (1...1000)
        .select {|num| num%3==0 || num%5==0}
        .each do |num|    
            sum += num
        end
    p sum
end

def problem2
    sumEven = 0
    fib = [1,2]
    
    1000.times do
        fib << fib[-2] + fib[-1]
        next unless fib[-1] + fib[-2] >= 4000000
        break
    end

    fib
        .select {|num| num%2==0}
        .each do |num|
            if(num%2==0)
                sumEven+= num
            end
        end

    p sumEven
end

def isPrime(num)
    maxFactor = (num**0.5).floor
    (2..maxFactor).each do |x|
        if(num % x == 0)
            return false
        end
    end

    return true
end

def problem3
    # The prime factors of 13195 are 5, 7, 13 and 29.
    # What is the largest prime factor of the number 600851475143 ?

    num = 600851475143
    factors = (2..(num**0.5).floor).select{|x| num % x ==0}    
    primeFactors = factors.select {|x| isPrime(x) }
    p primeFactors.max
end

def isPalindrome(num)
    strNumber = num.to_s
    if(strNumber.reverse == strNumber)
        return true
    end

    return false
end

def problem4
    maxPalindrome = -1
    (100..999).each do |x|
        (100..999).each do |y|
            product = x*y
            if( isPalindrome(product))
                if(product > maxPalindrome)
                    maxPalindrome = product
                end
            end
        end
    end
    p maxPalindrome
end

def problem5
    p 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13 * 17 * 19
end

def problem6
    # Find the difference between the sum of the squares 
    # of the first one hundred natural numbers and the square of the sum.
    sumOfSquares = 0
    (1..100).each do |x| 
        sumOfSquares = sumOfSquares + (x ** 2)
    end
    
    squareOfSum = 0
    (1..100).each do |x|
        squareOfSum = squareOfSum + x
    end
    squareOfSum = squareOfSum ** 2

    p squareOfSum - sumOfSquares 
end

def problem7
    # By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
    # What is the 10 001st prime number?

    prime = 2
    nextPrime = -1
    (2..10001).each do |primeIndex|
        nextPrime = prime+1
        until isPrime(nextPrime)
            nextPrime = nextPrime + 1
        end
        prime = nextPrime
    end
    p prime
end

def problem8
    num = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450"
    maxProduct = -1
    (0..987).each do |index|
        product = 1
        (0..12).each do |pos|            
            product = product * num[index + pos].to_i
        end            
        if(product > maxProduct)
            maxProduct = product
        end
    end
    
    p maxProduct
end

def problem9
    (1..1000).each do |c|
        (1..999).each do |b|
            a = 1000 - b - c
            if(a * a + b * b == c * c)                
                p (a * b * c)
                return
            end
        end
    end    
end

def problem10
    prime = 2
    nextPrime = -1
    sum = 0
    until nextPrime >= 2000000 
        sum = sum + prime
        nextPrime = prime+1
        until isPrime(nextPrime)
            nextPrime = nextPrime + 1
        end
        prime = nextPrime       
    end
    p sum
end

def problem11
    grid = Array.new(20) { Array.new(20) }
    grid[ 0] = %w(08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08)
    grid[ 1] = %w(49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00)
    grid[ 2] = %w(81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65)
    grid[ 3] = %w(52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91)
    grid[ 4] = %w(22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80)
    grid[ 5] = %w(24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50)
    grid[ 6] = %w(32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70)
    grid[ 7] = %w(67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21)
    grid[ 8] = %w(24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72)
    grid[ 9] = %w(21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95)
    grid[10] = %w(78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92)
    grid[11] = %w(16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57)
    grid[12] = %w(86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58)
    grid[13] = %w(19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40)
    grid[14] = %w(04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66)
    grid[15] = %w(88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69)
    grid[16] = %w(04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36)
    grid[17] = %w(20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16)
    grid[18] = %w(20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54)
    grid[19] = %w(01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48)

    maxProduct = -1

    #vertical
    (0..19).each do |x|
        (0..16).each do |y|
            product = grid[y][x].to_i() * grid[y+1][x].to_i() * grid[y+2][x].to_i() * grid[y+3][x].to_i()
            if(product > maxProduct)
                maxProduct = product
            end
        end
    end

    #horizontal
    (0..16).each do |x|
        (0..19).each do |y|
            product = grid[y][x].to_i() * grid[y][x+1].to_i() * grid[y][x+2].to_i() * grid[y][x+3].to_i()
            if(product > maxProduct)
                maxProduct = product
            end
        end
    end

    #diagonal like "\"
    (0..16).each do |x|
        (0..16).each do |y|
            product = grid[y][x].to_i() * grid[y+1][x+1].to_i() * grid[y+2][x+2].to_i() * grid[y+3][x+3].to_i()
            if(product > maxProduct)
                maxProduct = product
            end
        end
    end

    #diagonal like "/"
    (3..19).each do |x|
        (0..16).each do |y|
            product = grid[y][x].to_i() * grid[y+1][x-1].to_i() * grid[y+2][x-2].to_i() * grid[y+3][x-3].to_i()
            if(product > maxProduct)
                maxProduct = product
            end
        end
    end

    p maxProduct
end

def getDivisorCount(number)
    divisorCount = 0
    maxDivisor = (number**0.5).floor
    (1..maxDivisor).each do |divisor|
        if(number%divisor==0)
            divisorCount = divisorCount + 2
        end
    end
    if(number == maxDivisor**2)
        divisorCount = divisorCount - 2
    end
    return divisorCount
end

def problem12
    
    previousT = 1
    nextT = -1
    index = 1
    divisorCount = 0;

    while(divisorCount <= 500)
        maxDivisorCount = divisorCount
        
        index=index+1
        nextT = previousT + index
        divisorCount = getDivisorCount(nextT)
        previousT = nextT
    end
    p nextT
end

problem1
problem2
problem3
problem4
problem5
problem6
problem7
problem8
problem9
#problem10 #too slow
problem11
problem12