full_dict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,? _"

def mod_inverse(divisor, mod_num):
    for i in range(1, mod_num):
        if (divisor * i) % mod_num == 1:
            return i
    return None

def decode(input):
    result = ""
    mod_num = len(full_dict)
    index = 0
    
    for w in input:
        index += 1
        
        if w not in full_dict:
            result += w
            continue
        
        minv = mod_inverse(2 ** index, mod_num)
        decoded_index = (full_dict.index(w) * (minv)) % mod_num
        decoded_index = (decoded_index + minv - 1) % mod_num
        
        result += full_dict[decoded_index]
    
    return result;
