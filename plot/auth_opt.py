import matplotlib as mpl 
import matplotlib.pyplot as plt 
import numpy as np

def plot_stacked_bar(data, series_labels, category_labels=None, 
                     show_values=False, value_format="{}", y_label=None, 
                     colors=None, grid=False, reverse=False):
    """Plots a stacked bar chart with the data and labels provided.

    Keyword arguments:
    data            -- 2-dimensional numpy array or nested list
                       containing data for each series in rows
    series_labels   -- list of series labels (these appear in
                       the legend)
    category_labels -- list of category labels (these appear
                       on the x-axis)
    show_values     -- If True then numeric value labels will 
                       be shown on each bar
    value_format    -- Format string for numeric value labels
                       (default is "{}")
    y_label         -- Label for y-axis (str)
    colors          -- List of color labels
    grid            -- If True display grid
    reverse         -- If True reverse the order that the
                       series are displayed (left-to-right
                       or right-to-left)
    """

    ny = len(data[0])
    ind = list(range(ny))

    axes = []
    cum_size = np.zeros(ny)

    data = np.array(data)

    if reverse:
        data = np.flip(data, axis=1)
        category_labels = reversed(category_labels)

    for i, row_data in enumerate(data):
        color = colors[i] if colors is not None else None
        axes.append(plt.bar(ind, row_data, bottom=cum_size, 
                            label=series_labels[i], color=color))
        cum_size += row_data

    if category_labels:
        plt.xticks(ind, category_labels)

    if y_label:
        plt.ylabel(y_label)

    plt.legend()

    if grid:
        plt.grid()

    if show_values:
        for axis in axes:
            for bar in axis:
                w, h = bar.get_width(), bar.get_height()
                plt.text(bar.get_x() + w/2, bar.get_y() + h/2, 
                         value_format.format(h), ha="center", 
                         va="center")

# Auth : optimization

series_labels = ['Fetch subscription data', 'Send subscription data to Auth module', 'Perform authentication']

#       auth module in     subscription data prefetching       reuse of token
# C1 -     cloud                     n                                   n
# C2 -     cloud                     n                                   y
# C3 -     cloud                     y                                   n
# C4 -     cloud                     y                                   y
# C5 -      MEC                      n                                   n
# C6 -      MEC                      n                                   y
# C7 -      MEC                      y                                   n
# C8 -      MEC                      y                                   y
category_labels = ['C1', 'C2', 'C3', 'C4', 'C5', 'C6', 'C7', 'C8']

data = [
    [0.9, 0.9, 0.0, 0.0, 0.9, 0.9, 0.0, 0.0],
    [0.8, 0.8, 0.8, 0.8, 0.1, 0.1, 0.1, 0.1],
    [0.7, 0.3, 0.7, 0.3, 0.7, 0.3, 0.7, 0.3]
]

plot_stacked_bar(
    data, 
    series_labels, 
    category_labels=category_labels, 
    show_values=False, 
    value_format="{:.1f}",
    colors=['tab:orange', 'tab:green', 'tab:blue'],
    y_label="Latency (s)"
)

plt.title('Optimization for authentication')
plt.savefig('auth_opt.png')
plt.show()