import pandas as pd
pd.__version__

original_dict = {
    "col1": [1,2,3,4,5,6],
    "col2": [5,4,3,2,1,6],
    "col3": list('abcdeu'),
    "col4": [5,5,5,5,5,6],
    "col5": [5,4,5,5,5,6],
    "col6": [5,3,5,5,5,7],
    "col7": [5,1,5,5,5,7],
    "col8": [5,2,5,5,5,7],
    "col9": [5,1,5,5,5,7],
    "col10": [5,1,5,5,5,7],
    "col11": [5,1,5,5,5,7]
}

dataframe = pd.DataFrame(original_dict)
print(dataframe)

rename = {"col1":"1", "col2":"2"}
dataframe = dataframe.rename(rename, axis=1)
dataframe = dataframe.iloc[:,3:]

print(dataframe)

# tic = pd.read_csv('http://bit.ly/kaggletrain')
# print(tic.head(50))

# tic_copy = tic.copy()
# print(tic_copy.head())

# tic_copy.info(memory_usage="deep")