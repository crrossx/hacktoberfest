def calculate(s:str) ->str:
        res = 0
        sign = 1
        num = 0
        stack = []

        i = 0

        while(i < len(s)):
                if(s[i].isdigit()):
                        j = i
                        num = 0
                        while(j < len(s) and s[j].isdigit()):
                                num = num*10 + int(s[j])
                                j+=1

                        res += sign * num
                        i = j

                elif s[i] == '+':
                        sign = 1
                        i += 1

                elif s[i] == '-':
                        sign = -1
                        i += 1

                elif s[i] == '(':
                        stack.append(res)
                        stack.append(sign)

                        res = 0
                        sign = 1
                        i += 1

                elif s[i] == ')':
                        sign = stack.pop()
                        prevRes = stack.pop()

                        res = prevRes + sign * res
                        i += 1
                else:
                        i += 1

        return res


s = input()
result = calculate(s)
print(result)
