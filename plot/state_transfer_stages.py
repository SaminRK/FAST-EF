import matplotlib as mpl 
import matplotlib.pyplot as plt 
import numpy as np
import matplotlib.patches as mpatches

# State transfer: two stages

state_transfer_stages = ['service reg', 'service req', 'notify neighbours', 'notify UE enters' \
    , 'ue entered', 'state req', 'state resp', 'user state']
latency = [0.1, 0.1, 0.7, 0.1, 0.1, 0.6, 0.9, 0.1]
min_latency = [0.07, 0.07, 0.65, 0.07, 0.07, 0.55, 0.85, 0.07]
max_latency = [0.12, 0.12, 0.75, 0.12, 0.12, 0.65, 0.95, 0.12]
yerr = [np.subtract(latency, min_latency), np.subtract(max_latency, latency)]

fig, ax = plt.subplots()

plt.bar(state_transfer_stages, latency, color=['blue', 'blue', 'blue', 'blue' \
    , 'green', 'green', 'green', 'green'], yerr=yerr,  capsize=5)

plt.ylabel('Latency (s)')

blue_patch = mpatches.Patch(color='blue', label='setup')
green_patch = mpatches.Patch(color='green', label='handover')
plt.legend(handles=[blue_patch, green_patch])

labelsx = ax.get_xticklabels()
plt.setp(labelsx, rotation=30, fontsize=10, ha='right')


plt.title('State transfer: two stages')
plt.savefig('state_transfer_stages.png')
plt.show()