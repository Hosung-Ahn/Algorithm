dfs(root);

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 1) result++;
    }
    cout << result;