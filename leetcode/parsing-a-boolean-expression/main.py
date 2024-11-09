# https://leetcode.com/problems/parsing-a-boolean-expression/?envType=daily-question&envId=2024-10-20

class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        operator_stack = ["&"]
        value_stack = [[]]
        for c in expression:
            if c == ",":
                continue
            if c == "!" or c == "&" or c == "|":
                operator_stack.append(c)
                value_stack.append([])
                continue
            # assume no consecutive, e.g. &(())
            if c == "(":
                continue
            if c == "t" or c == "f":
                value_stack[-1].append(c)
                continue
            else: # )
                operator = operator_stack.pop()
                values = value_stack.pop()

                evaluated = None
                if operator == "&":
                    evaluated = "t"
                    for value in values:
                        if value == "f":
                            evaluated = "f"
                            break
                elif operator == "|":
                    evaluated = "f"
                    for value in values:
                        if value == "t":
                            evaluated = "t"
                            break
                else:
                    if values[0] == "t":
                        evaluated = "f"
                    else:
                        evaluated = "t"

                value_stack[-1].append(evaluated)

        # print("----", len(value_stack))
        return False if value_stack[0][0] == "f" else True

# print(Solution().parseBoolExpr("t")) # true
# print(Solution().parseBoolExpr("f")) # false
# print(Solution().parseBoolExpr("!(f)")) # true
# print(Solution().parseBoolExpr("!(t)")) # false

# print(Solution().parseBoolExpr("&(t,t)")) # true
# print(Solution().parseBoolExpr("&(t,f)")) # false
# print(Solution().parseBoolExpr("|(t,f)")) # true
# print(Solution().parseBoolExpr("|(f,t)")) # true
# print(Solution().parseBoolExpr("|(f,f)")) # false
# print(Solution().parseBoolExpr("|(f,f)")) # false

print(Solution().parseBoolExpr("&(|(f))")) # false
print(Solution().parseBoolExpr("|(f,f,f,t)")) # true
print(Solution().parseBoolExpr("!(&(f,t))")) # true
