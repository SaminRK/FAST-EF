import matplotlib as mpl 
import matplotlib.pyplot as plt 
import numpy as np

def main():
    state_transfer_sizes = ['10 KB', '1 MB', '10 MB']

    data = [[70, 341, 2713],
    [34, 66, 234]]
    labels = ['without prefetching', 'with prefetching']

    X = np.arange(3)

    # ax1 top, ax2 bottom
    fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True)
    fig.subplots_adjust(hspace=0.08)

    ax1.bar(X + 0.00, data[0], color = 'b', width = 0.33, label=labels[0])
    ax1.bar(X + 0.33, data[1], color = 'g', width = 0.33, label=labels[1])

    ax2.bar(X + 0.00, data[0], color = 'b', width = 0.33, label=labels[0])
    ax2.bar(X + 0.33, data[1], color = 'g', width = 0.33, label=labels[1])

    ax1.set_ylim(500, 3000)  
    ax2.set_ylim(0, 500)  

    plt.xticks(ticks=np.arange(3) + 0.33 / 2, labels=state_transfer_sizes)
    plt.ylabel('Latency (ms)')
    plt.xlabel('State sizes')

    ax1.legend()

    plt.savefig('state_transfer_sizes.png')
    plt.savefig('state_transfer_sizes.svg')
    plt.show()

if __name__ == '__main__':
    main()