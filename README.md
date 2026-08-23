# Leetcode Solved Problems

Automated synchronization of LeetCode accepted submissions to GitHub using [joshcai/leetcode-sync](https://github.com/joshcai/leetcode-sync).

## How it Works
A GitHub Actions workflow is scheduled to run daily to fetch newly accepted submissions from LeetCode and commit them to this repository. The sync process also maintains proper commit dates corresponding to the time you solved each question.

---

## Setup Instructions

To configure this automation for your repository, follow these steps:

### 1. Retrieve LeetCode Credentials
You need your LeetCode session cookies to allow the GitHub Action to fetch your submissions:
1. Log in to [LeetCode](https://leetcode.com).
2. Open your browser's Developer Tools (typically press `F12` or right-click anywhere and select **Inspect**).
3. Select the **Application** tab (on Chrome/Edge) or the **Storage** tab (on Firefox).
4. Under the **Cookies** section in the left panel, expand `https://leetcode.com`.
5. Locate and copy the values for:
   * `LEETCODE_SESSION`
   * `csrftoken` (This will be used as `LEETCODE_CSRF_TOKEN`)

> [!WARNING]
> These cookies expire after a few weeks or months. If the sync workflow stops working and reports authentication errors, you will need to repeat this step and update the secrets on GitHub.

### 2. Save Secrets on GitHub
1. Go to your repository on GitHub: [KMohnishM/Leetcode_solved](https://github.com/KMohnishM/Leetcode_solved).
2. Navigate to **Settings** > **Secrets and variables** > **Actions**.
3. Click on **New repository secret**.
4. Add the first secret:
   * **Name**: `LEETCODE_SESSION`
   * **Value**: *(Paste the value of `LEETCODE_SESSION` copied in Step 1)*
5. Click **Add secret**.
6. Click **New repository secret** again.
7. Add the second secret:
   * **Name**: `LEETCODE_CSRF_TOKEN`
   * **Value**: *(Paste the value of `csrftoken` copied in Step 1)*
8. Click **Add secret**.

### 3. Grant Workflow Commit Permissions
Since the Action needs to write files and push commits back to your repository:
1. Go to **Settings** > **Actions** > **General**.
2. Scroll down to **Workflow permissions**.
3. Select **Read and write permissions**.
4. Click **Save**.

### 4. Run the Sync Manually
1. Go to the **Actions** tab of your repository.
2. Select the **Sync Leetcode** workflow on the left side.
3. Click the **Run workflow** dropdown on the right and click **Run workflow**.
4. Once completed, your solved problems will be synced and commit details will appear in your repository!
