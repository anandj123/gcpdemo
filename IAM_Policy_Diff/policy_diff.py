import yaml
from deepdiff import DeepDiff
from yaml.loader import SafeLoader
import pprint 
df1 = {}
df2 = {}
pp = pprint.PrettyPrinter(indent=4)
with open(r'a.yaml','r') as file1:
    df1 = yaml.load_all(file1, Loader=SafeLoader)

    with open(r'b.yaml','r') as file2:
        df2 = yaml.load_all(file2,Loader=SafeLoader)

        ddiff1 = DeepDiff(df1,df2)
        pp.pprint(ddiff1)
        print("---------")

