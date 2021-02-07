import numpy as np
import pandas as pd

df = pd.DataFrame(
	[[21, 72, 67],
	[23, 78, 69],
	[32, 74, 56],
	[52, 54, 76]],
	columns=['a', 'b', 'c'])
	
npf = df.to_numpy()

print(npf)