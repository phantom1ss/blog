import importlib.util
import os
import sys
import ast
from decimal import Decimal, InvalidOperation

islog = False

class Result:
    def __init__(self, md_url, py_url, score=0):
        self.md_url = md_url
        self.py_url = py_url
        self.score = score
        self.code = None

    def add_score(self, points):
        self.score += points

    def set_code(self, code):
        self.code = code

    def __str__(self):
        return f"URL: {self.md_url}, Score: {self.score}, Code: {self.code}"

def log(str):
    if islog:
        print(str)

def find_term_in_file(file_path, search_term):
    with open(file_path, 'r') as file:
        lines = file.readlines()
    for line in lines:
        if search_term in line:
            return line.strip()
    return None

def extract_urls_from_line(line):
    parts = line.split(',')
    md_url = parts[-1]
    py_url = md_url.replace('.md', '.py')
    return md_url, py_url

def import_function_from_file(module_name, file_path):
    spec = importlib.util.spec_from_file_location(module_name, file_path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module

def run_function_from_module(module, func_name, *args):
    try:
        if hasattr(module, func_name):
            func = getattr(module, func_name)
            return func(*args)
        else:
            print(f"The module does not have a '{func_name}' function.")
            return None
    except Exception as e:
        print(f"Error: {str(e)}")
        return None

def solveup(term, *args):
    search_term = term
    file_path = "/home/mrrobot/Desktop/blog/Ai"
    
    line = find_term_in_file(file_path, search_term)
    
    if not line:
        log(f"Search term '{search_term}' not found in the file.")
        return None
    
    md_url, py_url = extract_urls_from_line(line)
    
    module_name = os.path.basename(py_url).replace('.py', '')
    py_file_path = py_url.replace('https://cybersecctf.github.io/blog/', '/home/mrrobot/Desktop/blog/')
    
    if not os.path.exists(py_file_path):
        log(f"File not found: {py_file_path}")
        return None
    
    module = import_function_from_file(module_name, py_file_path)
    result = run_function_from_module(module, 'solve', *args)
    
    if result is not None:
        log(f"Function: solve")
        log(f"Arguments: {args}")
        log(f"Result: {result}")
        return result
    else:
        log("Function returned None")
        return None

def detect_value_type(value):
    log(f"Detecting value type for: {value}")
    try:
        int_value = int(value)
        if '.' not in value and 'e' not in value.lower():
            return 'int'
    except ValueError:
        pass

    try:
        decimal_value = Decimal(value)
        if decimal_value == float(decimal_value):
            return 'float'
        else:
            return 'decimal'
    except InvalidOperation:
        pass

    try:
        float_value = float(value)
        return 'float'
    except ValueError:
        pass

    return 'string'

def set(val, i=1, type="auto", alert="usage argument -v"):
    log(f"Setting value: val={val}, i={i}, type={type}")
    
    if i <= 0:
        log("Argument value should be more than 0, not", i)
        return val
    
    if len(sys.argv) > i:
        val = sys.argv[i]
    
    try:
        if not isinstance(val, str):
            return val
        if type == "auto":
            type = detect_value_type(val)
        if type == "float":
            val = float(val)
        elif type == "int":
            val = int(val)
        elif type == "decimal":
            val = Decimal(val)
        elif val.startswith("[") and val.endswith("]") and "," in val:
            val = ast.literal_eval(val)
    except Exception as e:
        log(f"Exception in val {val}: {str(e)}")
    
    if len(sys.argv) == 1:
        if alert == "usage argument -v":
            log(alert + " " + str(i) + "th value")
        else:
            print(alert)
    
    return val


