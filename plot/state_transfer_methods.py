import matplotlib as mpl 
import matplotlib.pyplot as plt 
import numpy as np

# App resumption latency : different methods for state transfer

# S1 - State transfer via cloud
# S2 - Without prefetching states
# S3 - With prefetching states
transfer_method = ['S1', 'S2', 'S3']
latency = [4.2, 3.2, 1.6]
min_latency = [3.7, 3.0, 1.5]
max_latency = [4.4, 3.3, 1.8]
yerr = [np.subtract(latency, min_latency), np.subtract(max_latency, latency)]

plt.bar(transfer_method, latency, yerr=yerr, capsize=8)
plt.ylabel('Latency (s)')
plt.savefig('state_transfer_methods.png')
plt.title('App resumption latency with different methods for state transfer')
plt.show()