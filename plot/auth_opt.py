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

    hatches = ['//', '\\\\\\', '--']
    handles = []
    for i, row_data in enumerate(data):
        color = colors[i] if colors is not None else None
        b = plt.bar(ind, row_data, bottom=cum_size, hatch=hatches[i],
                            label=series_labels[i], fill=False, color=None, edgecolor=color)
        axes.append(b)
        handles.append(b)
        cum_size += row_data

    if category_labels:
        plt.xticks(ind, category_labels)

    if y_label:
        plt.ylabel(y_label)

    plt.legend(handles=handles[::-1])

    if grid:
        plt.grid()

    if show_values:
        for axis in axes:
            for bar in axis:
                w, h = bar.get_width(), bar.get_height()
                plt.text(bar.get_x() + w/2, bar.get_y() + h/2, 
                         value_format.format(h), ha="center", 
                         va="center")

def main():
    # Auth : optimization

    series_labels = ['Auth server', 'Access control', 'Registration']

    #       auth module in     subscription data prefetching       reuse of token
    # C1 -     cloud                     n                                   n
    # C2 -     cloud                     n                                   y
    # C3 -     cloud                     y                                   n
    # C4 -     cloud                     y                                   y
    # C5 -      MEC                      n                                   n
    # C6 -      MEC                      n                                   y
    # C7 -      MEC                      y                                   n
    # C8 -      MEC                      y                                   y
    category_labels = ['CUA', 'CUT', 'CPA', 'CPT', 'MUA', 'MUT', 'MPA', 'MPT']

    data = [
        [3.181, 0.650, 3.204, 0.650, 0.805, 0.100, 0.796, 0.100],
        [0.320, 0.340, 0.036, 0.037, 0.301, 0.340, 0.038, 0.037],
        [0.864, 0.915, 0.828, 0.827, 0.910, 0.926, 0.835, 0.810]
    ]

    plt.style.use('seaborn-poster')
    mpl.rcParams.update({'font.size': 12})

    plot_stacked_bar(
        data, 
        series_labels, 
        category_labels=category_labels, 
        show_values=False, 
        value_format="{:.1f}",
        colors=['tab:blue', 'tab:orange', 'tab:green'],
        y_label="Latency (s)"
    )

    plt.xlabel('Scenarios')
    # plt.title('Optimization for authentication')
    plt.savefig('auth_opt.png')
    plt.savefig('auth_opt.svg')
    plt.show()

if __name__ == '__main__':
    main()
